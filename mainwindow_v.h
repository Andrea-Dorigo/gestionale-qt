
#include "listview.h"
#include "listmodeladapter.h"
#include <QWidget>
#include "combobox_inserimento.h"
#include "qfilterproxymodel.h"

class ListView;
class ListModelAdapter;
class QFilterProxyModel;

class MainWindow_v : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow_v(QWidget *parent = 0);
    ~MainWindow_v() override;

private:
    combobox_inserimento* cmb_ins;
    QComboBox* filtro;
    QLineEdit* searchbar;
    QFilterProxyModel* proxymodel;
    ListModelAdapter* model;
    ListView* view;
private slots:
    void addProdotto(const QString&);
    void removeProdotto();
    void textFilterChanged();
};

