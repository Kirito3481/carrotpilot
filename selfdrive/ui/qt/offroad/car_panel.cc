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
  });

  refresh();
}

void SelectCar::refresh() {
  QString carName = QString::fromStdString(params.get("CarName"));
  if (carName.length() > 1) {
    setValue(carName);
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