# QT_Nest_with_clipper_backend
QT gui with 2d plate nesting algoritmme. The backend is configured for clipper in this upload.

The test input is a box of 100x100mm.

In the Mainwindow.cpp we have a test box that is nested in total 3+1 times.
Keep the contour input clockwise cw.
The input startpoint must be the same as the input endpoint.

Nesting output :

![alt text](https://raw.githubusercontent.com/grotius-cnc/QT_Nest_with_clipper_backend/master/nest_test.png)

Orginal picture :

![alt text](https://raw.githubusercontent.com/grotius-cnc/QT_Nest_with_clipper_backend/master/test.png)


If the git clone does not work imidiately on linux 64 bit, follow these steps:

- Installation guide for 2 dependencies, when you have problems.
- Put the downloads just as the current qt project directory structure for clipper and nlopt, some of the header files are searching in that area.

Info: If the "cmake" command fails, start again with a clean directory.

This project is a orginal git clone off : https://github.com/tamasmeszaros/libnest2d.git

for the nlopt library :

documentation : https://nlopt.readthedocs.io/en/latest/NLopt_Installation/

1. git clone https://github.com/stevengj/nlopt.git
2. in the nlopt directory open terminal :

        a. cmake -DCMAKE_INSTALL_PREFIX=/home/user/QT_Nest/nlopt/   "change to your directory adres"
        b. make
        c. make install

for the clipper library :

download the zip from : https://sourceforge.net/projects/polyclipping/
1. unzip the package.
2. cd cpp
3. in terminal :

        a. cmake -DCMAKE_INSTALL_PREFIX=/home/user/QT_Nest/clipper/  "change to your directory adres"
        b. make
        c. make install

Link the libraries in the qt .pro file like :

        LIBS +=	-L$$PWD/clipper/ -lpolyclipping \
                -L$$PWD/nlopt/ -lnlopt
        
The nesting program is tested on:

        Debian 10, with QT installation 
        Qt Creator 4.12.3,
        Based on Qt 5.14.2 (GCC 5.3.1 20160406 (Red Hat 5.3.1-6), 64 bit)
        Built on Jun 16 2020 04:15:35
        From revision 48e46132e3




data input based on integer xy coordinates example:

    std::vector<Item> input; //contour container

    ClipperLib::IntPoint point; //clipper point xy container
    int x=0;
    int y=0;
    point={x,y};
    ClipperLib::Polygon poly; //clipper polygon container
    poly.Contour.push_back(point); //add point to polygon

    x=0; //second point
    y=100;
    point={x,y};
    poly.Contour.push_back(point);

    x=100; //third point
    y=100;
    point={x,y};
    poly.Contour.push_back(point);

    x=100; //fourth point
    y=0;
    point={x,y};
    poly.Contour.push_back(point);

    x=0; //the enpoint must be the same as the startpoint to close the contour for clipper
    y=0;
    point={x,y};
    poly.Contour.push_back(point);

    input.push_back({poly.Contour}); //add the polygon to the contour container
    
        ClipperLib::Polygon pol;
    pol.Contour.push_back({0,0});
    pol.Contour.push_back({0,100});
    pol.Contour.push_back({100,100});
    pol.Contour.push_back({100,0});
    pol.Contour.push_back({0,0});

    input.push_back({{0,0},{0,100},{100,100},{100,0},{0,0}});
    input.push_back({{0,0},{0,100},{100,100},{100,0},{0,0}});
    input.push_back({pol.Contour});


    std::vector<Item> inputs;
    //input.insert(input.end(), input1.begin(), input1.end());
    //input.insert(input.end(), test.begin(), test.end());
    inputs.insert(inputs.end(), input.begin(), input.end());

    // Perform the nesting with a box shaped bin
    size_t bins = nest(inputs, Box(150000000, 150000000));

    // Retrieve resulting geometries
    for(Item& r : inputs) {
        auto polygon = r.transformedShape();
        // render polygon...

        std::cout<<"r.begin.x"<<r.begin()->X<<std::endl;
        std::cout<<"r.begin.y"<<r.begin()->Y<<std::endl;

        std::cout<<"r.rotation degrees: "<<r.rotation().toDegrees()<<std::endl;

        std::cout<<"translation.x"<< r.translation().X<<std::endl;
        std::cout<<"translation.y"<< r.translation().Y<<std::endl;

        std::cout<<"polygon.contour.begin.x"<<polygon.Contour.begin()->X<<std::endl;
        std::cout<<"polygon.contour.begin.y"<<polygon.Contour.begin()->Y<<std::endl;

    }
