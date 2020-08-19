#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Modello; // definizioni incomplete
class ListView;
class ListModelAdapter;
//class QFilterProxyModel;
class QLineEdit;
class QComboBox;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* = nullptr);
    ~MainWindow() override;
    QSize sizeHint() const override;

private:
    QComboBox* inserimento;
//    QComboBox* filtro;
//    QFilterProxyModel* proxymodel;
    ListModelAdapter* model;
    QLineEdit* searchbar;
    ListView* view;

/*    void loadData();*/ // non è chiamata da un pulsante quindi non serve sia uno SLOT

private slots:
//    void saveData();
    void addProdotto(const QString&);
//    void removeMembroSocieta();
//    void textFilterChanged();
};

#endif // MAINWINDOW_H
