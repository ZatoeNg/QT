#ifndef PRO_SET_PAGE_H
#define PRO_SET_PAGE_H

#include <QWizardPage>

namespace Ui {
class ProSetPage;
}

class ProSetPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ProSetPage(QWidget *parent = nullptr);
    ~ProSetPage();
public:
    void get_pro_settings(QString& name,QString& path);
protected:
    virtual bool isComplete() const;

private slots:
    void on_browse_clicked();

private:
    Ui::ProSetPage *ui;
};

#endif // PRO_SET_PAGE_H
