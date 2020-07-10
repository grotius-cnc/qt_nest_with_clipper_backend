#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <include/libnest2d/libnest2d.hpp>
using namespace libnest2d;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{

    //Startpoint first, endpoint=startpoint last !!
    //only cw contours are welcome.
    std::vector<Item> input1(3,
    {
                                 {0, 0},
                                 {0, 100},
                                 {100, 100},
                                 {100, 0},
                                 {0, 0},

                             });
    std::vector<Item> input2(1,
    {
                                 {0, 0},
                                 {0, 100},
                                 {100, 100},
                                 {100, 0},
                                 {0, 0},
                             });

    std::vector<Item> input;
    input.insert(input.end(), input1.begin(), input1.end());
    input.insert(input.end(), input2.begin(), input2.end());

    // Perform the nesting with a box shaped bin
    size_t bins = nest(input, Box(150000000, 150000000));

    // Retrieve resulting geometries
    for(Item& r : input) {
        auto polygon = r.transformedShape();
        // render polygon...

        std::cout<<"r.begin.x"<<r.begin()->X<<std::endl;
        std::cout<<"r.begin.y"<<r.begin()->Y<<std::endl;

        std::cout<<"r.rotation degrees: "<<r.rotation().toDegrees()<<std::endl;

        std::cout<<"r.area: "<<r.area()<<std::endl;
        std::cout<<"translation.x"<< r.translation().X<<std::endl;
        std::cout<<"translation.y"<< r.translation().Y<<std::endl;

        std::cout<<"polygon.contour.begin.x"<<polygon.Contour.begin()->X<<std::endl;
        std::cout<<"polygon.contour.begin.y"<<polygon.Contour.begin()->Y<<std::endl;

    }













    //    // Example polygons
    //    std::vector<Item> input1(5,
    //    {
    //        {0, 0},
    //        {100, 0},
    //        {100, 100},
    //        {0, 100}

    //    });

    //    std::vector<Item> input2(2,
    //    {
    //        {0, 0},
    //        {50, 50},
    //        {0, 100},
    //        {-50, 50}

    //    });


    //    std::vector<Item> input;
    //    input.insert(input.end(), input1.begin(), input1.end());
    //    input.insert(input.end(), input2.begin(), input2.end());

    //    size_t bins = libnest2d::nest(input, Box(1000, 1000,{0,0}));


    //    // Retrieve resulting geometries
    //       for(Item& r : input) {
    //           auto polygon = r.transformedShape();
    //           // render polygon...

    //           std::vector<Item>::iterator it;



    //           std::cout<<"r.begin.x"<<r.begin()->X<<std::endl;
    //           std::cout<<"r.begin.y"<<r.begin()->Y<<std::endl;

    //           std::cout<<"r.rotation degrees: "<<r.rotation().toDegrees()<<std::endl;

    //           std::cout<<"r.area: "<<r.area()<<std::endl;
    //           std::cout<<"translation.x"<< r.translation().X<<std::endl;
    //           std::cout<<"translation.y"<< r.translation().Y<<std::endl;

    //           std::cout<<"polygon.contour.begin.x"<<polygon.Contour.begin()->X<<std::endl;
    //           std::cout<<"polygon.contour.begin.y"<<polygon.Contour.begin()->Y<<std::endl;



    ////           for(unsigned int i=0; i<polygon.Contour.size(); i++){
    ////                std::cout<<"X: "<<polygon.Contour.at(i).X<< "Y: "<<polygon.Contour.at(i).Y;
    ////           }


    //       }

}
