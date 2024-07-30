#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置整个界面的背景颜色
    this->setStyleSheet("QWidget { background-color: #FFF8DC; }");



    ui->Battery_level_display->setValue(80);    //电池电量显示



    //航角显示
    QGroupBox *firstgroupBox = ui->a_groupBox;
    firstgroupBox->setStyleSheet(R"(
        QGroupBox#a_groupBox {
            border: 2px groove #34495E; /* 深青色沟边边框 */
            border-radius: 10px;
            margin: 10px;
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #ECF0F1, stop: 1 #BDC3C7); /* 渐变背景色 */
            box-shadow: none; /* 移除扁平化设计中的阴影 */
        }
        QGroupBox#a_groupBox:title {
            background-color: #34495E; /* 深青色背景色 */
            color: #FFFFFF; /* 白色文本颜色 */
            font: bold 16px 'Arial', sans-serif; /* 使用无衬线字体 */
            text-align: center;
            padding: 5px;
            min-height: 20px; /* 调整标题栏的高度以适应字体大小 */
        }
        /* 移除禁用状态下的背景色，因为我们不使用这个状态 */
        QGroupBox#a_groupBox:title:disabled {
            background-color: transparent;
        }
        /* 为文本标签设置样式 */
        QGroupBox#a_groupBox QLabel {
            border: none;
            background: transparent;
            color: #34495E; /* 深青色文本颜色 */
            font: 14px;
            padding: 5px;
        }
        /* 为输入控件设置样式 */
        QGroupBox#a_groupBox QTextEdit {
            border: 1px solid #34495E; /* 深青色边框 */
            border-radius: 3px;
            padding: 5px;
            background-color: #FFFFFF; /* 白色背景 */
            color: #34495E; /* 深青色文本 */
        }
    )");
    ui->PitchCompass->setValue(12);             //俯仰角
    ui->Pitch_TextLabel->setText("俯仰角：12°");
    ui->RollCompass->setValue(120);             //横滚角
    ui->Roll_TextLabel->setText("横滚角：120°");
    ui->YawCompass->setValue(255);              //偏航角
    ui->Yaw_TextLabel->setText("偏航角：255°");



    //罗盘时速高度
    QGroupBox *secondGroupBox = ui->b_groupBox;
    secondGroupBox->setStyleSheet(R"(
        QGroupBox#b_groupBox {
            border: 2px groove #8B4513; /* 棕色沟边边框 */
            border-radius: 10px;
            margin: 10px;
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #F5F5DC, stop: 1 #DEB887); /* 渐变背景色 */
        }
        QGroupBox#b_groupBox:title {
            background-color: #8B4513;     /* 棕色背景色 */
            color: #FFFFE0;                /* 浅黄色文本颜色 */
            font: bold 14px 'Times New Roman', serif; /* 使用衬线字体 */
            text-align: center;
            padding: 5px;
        }
    )");
    //高度计
    ui->altimeter->setValue(30);
    ui->heights_TextLabel->setText("高度：30米");
    //罗盘
    ui->compass->setValue(270);
    //速度计
    ui->speedometer->setValue(60);



    //航姿仪表
    QGroupBox *thirdGroupBox = ui->c_groupBox;
    thirdGroupBox->setStyleSheet(R"(
        QGroupBox#c_groupBox {
            border: 2px groove #FF4500; /* 橙色沟边边框 */
            border-radius: 10px;
            margin: 10px;
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                stop: 0 #FFE5B4, stop: 1 #FFA500); /* 橙色渐变背景色 */
        }
        QGroupBox#c_groupBox:title {
            background-color: #FF4500; /* 橙色背景色 */
            color: #FFFFFF; /* 白色文本颜色 */
            font: bold 14px 'Helvetica', sans-serif; /* 使用无衬线字体 */
            text-align: center;
            padding: 5px;
            min-height: 20px; /* 调整标题栏的高度以适应字体大小 */
        }
        /* 由于我们采用了沟边边框，可以移除阴影效果 */
        QGroupBox#c_groupBox:title:disabled {
            background-color: #FF4500;
        }
        /* 为文本标签设置样式 */
        QGroupBox#c_groupBox QLabel {
            border: none;
            background: transparent;
            color: #333333; /* 深色文本颜色，增加对比度 */
            font: 14px;
            padding: 5px;
        }
        /* 为输入控件设置样式 */
        QGroupBox#c_groupBox QTextEdit {
            border: 1px solid #FF4500; /* 橙色边框 */
            border-radius: 3px;
            padding: 5px;
            background-color: #FFFFFF; /* 白色背景 */
            color: #333333; /* 深色文本 */
        }
        /* 为按钮设置样式，如果groupBox中包含按钮 */
        QGroupBox#c_groupBox QPushButton {
            border: 1px solid #FF4500;
            border-radius: 3px;
            background-color: #FFA500;
            color: #FFFFFF;
            padding: 5px;
            margin: 2px;
        }
        /* 为按钮悬停效果设置样式 */
        QGroupBox#c_groupBox QPushButton:hover {
            background-color: #FF8C00;
        }
    )");




    //数据表格
    QGroupBox *fourthGroupBox = ui->d_groupBox;
    fourthGroupBox->setStyleSheet(R"(
        QGroupBox {
            border: 1px solid #555; /* 边框颜色 */
            border-radius: 10px; /* 边框圆角 */
            margin-top: 10px; /* 上边距 */
            background-color: #00008B; /* 深蓝色背景颜色 */
            box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.1); /* 阴影效果 */
        }
        QGroupBox:title {
            subcontrol-origin: margin;
            subcontrol-position: top center;
            padding: 0 5px;
            background-color: #555; /* 标题背景颜色 */
            color: #fff; /* 标题文本颜色 */
            font: bold 14px; /* 字体样式 */
        }
    ))");


















}

MainWindow::~MainWindow()
{
    delete ui;
}

