#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_BotonAjusteBrillo_clicked();

    void on_BotonSalir_clicked();

    void on_buton_elegirImagen_clicked();

    //void inicializacion();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
