#ifndef EDITOR_H
#define EDITOR_H

#include <QDialog>
#include "delegate.h"
class QComboBox;
class QLabel;
class QSpinBox;
class QPushButton;

class MyEditor: public QDialog
{ friend class Delegate;

  Q_OBJECT
  public:
    MyEditor(QWidget* parent= nullptr);
  signals:
    void editingFinished();
  private:
    QLabel* l1;
    QLabel* l2;
    QLabel* l3;
    QComboBox* c1;
    QComboBox* c2;
    QSpinBox* box;
    QPushButton* button;
};

#endif // EDITOR_H
