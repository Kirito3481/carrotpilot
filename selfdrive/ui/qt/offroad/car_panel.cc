#include "selfdrive/ui/qt/offroad/car_panel.h"

static QStringList get_list(const char* path)
{
    QStringList stringList;
    QFile textFile(path);
    if (textFile.open(QIODevice::ReadOnly))
    {
        QTextStream textStream(&textFile);
        while (true)
        {
            QString line = textStream.readLine();
            if (line.isNull())
                break;
            else
                stringList.append(line);
        }
    }

    return stringList;
}

SelectCar::SelectCar() :
  ButtonControl(
    tr("Select Car"),
    tr("SELECT"),
    tr("Force recognition of the selected car without recognizing it through fingerprint.")
  ) {

  QObject::connect(this, &ButtonControl::clicked, [=]() {
    QStringList supportedCars = {tr("[ Not selected ]")};
    supportedCars.append(get_list("/data/params/d/SupportedCars"));
    supportedCars.append(get_list("/data/params/d/SupportedCars_gm"));
    supportedCars.append(get_list("/data/params/d/SupportedCars_toyota"));

    QString selection = MultiOptionDialog::getSelection(tr("Select a car"), supportedCars, (selectedCar.length() > 1) ? selectedCar : tr("[ Not selected ]"), this);

    if (!selection.isEmpty()) {
      if (selection == tr("[ Not selected ]")) {
        params.remove("CarSelected3");
      } else {
        params.put("CarSelected3", selection.toStdString());
      }

      refresh();

      ConfirmationDialog::alert(tr("You need to restart the car for the changes to take effect."), this);
    }
  });

  refresh();
}

void SelectCar::refresh() {
  selectedCar = QString::fromStdString(params.get("CarSelected3"));
  if (selectedCar.length() > 1) {
    setValue(selectedCar);
  } else {
    setValue(QString::fromStdString(params.get("CarName")));
  }
}

CarPanel::CarPanel(SettingsWindow *parent) : ListWidget(parent) {
  addItem(new SelectCar());

  addItem(new CValueControl("HyundaiCameraSCC", "HYUNDAI: CAMERA SCC", "Connect the SCC's CAN line to CAM", "../assets/offroad/icon_shell.png", 0, 1, 1));
  addItem(new ParamControl("EnableRadarTracks", "Enable RadarTrack", "", "../assets/offroad/icon_shell.png", this));
  addItem(new ParamControl("CanfdHDA2", "CANFD: HDA2 mode", "", "../assets/offroad/icon_shell.png", this));
}

void CarPanel::updateToggles() {
}

void CarPanel::showEvent(QShowEvent *event) {
  updateToggles();
}