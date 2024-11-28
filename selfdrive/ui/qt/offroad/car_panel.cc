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

    QString selection = MultiOptionDialog::getSelection(tr("Select a car"), supportedCars, selectedCar, this);

    if (!selection.isEmpty()) {
      if (selection == tr("[ Not selected ]")) {
        params.remove("CarSelected3");
      } else {
        params.put("CarSelected3", selection.toStdString());
        refresh();
      }
    }

    ConfirmationDialog::alert(tr("You need to restart the car for the changes to take effect."), this);
  });

  refresh();
}

void SelectCar::refresh() {
  selectedCar = QString::fromStdString(params.get("CarSelected3"));
  if (selectedCar.length() > 1) {
    setValue(selectedCar);
  } else {
    setValue(tr("[ Not selected ]"));
  }
}

CarPanel::CarPanel(SettingsWindow *parent) : ListWidget(parent) {
  addItem(new SelectCar());
}

void CarPanel::updateToggles() {
}

void CarPanel::showEvent(QShowEvent *event) {
  updateToggles();
}