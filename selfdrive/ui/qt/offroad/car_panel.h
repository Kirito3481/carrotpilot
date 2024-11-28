#pragma once

#include "selfdrive/ui/qt/offroad/settings.h"

class SelectCar : public ButtonControl {
  Q_OBJECT

public:
  SelectCar();

private:
  Params params;
  QString selectedCar = QString::fromStdString(params.get("CarSelected3"));

  void refresh();
};

class CarPanel : public ListWidget {
  Q_OBJECT
public:
  explicit CarPanel(SettingsWindow *parent);
  void showEvent(QShowEvent *event) override;

private:
  Params params;

private slots:
  void updateToggles();
};