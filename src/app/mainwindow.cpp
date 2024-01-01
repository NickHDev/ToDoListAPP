#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addItem();

private:
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QPushButton *addButton;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), listWidget(new QListWidget), lineEdit(new QLineEdit), addButton(new QPushButton("Add"))
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    layout->addWidget(lineEdit);
    layout->addWidget(addButton);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addItem);
}

void MainWindow::addItem()
{
    if (!lineEdit->text().isEmpty()) {
        listWidget->addItem(lineEdit->text());
        lineEdit->clear();
    }
}