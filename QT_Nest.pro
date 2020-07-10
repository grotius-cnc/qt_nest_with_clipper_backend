QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14 console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/libnest2d.cpp

HEADERS += \
    include/libnest2d/backends/clipper/clipper_polygon.hpp \
    include/libnest2d/backends/clipper/geometries.hpp \
    include/libnest2d/common.hpp \
    include/libnest2d/geometry_traits.hpp \
    include/libnest2d/geometry_traits_nfp.hpp \
    include/libnest2d/libnest2d.hpp \
    include/libnest2d/nester.hpp \
    include/libnest2d/optimizer.hpp \
    include/libnest2d/optimizers/nlopt/genetic.hpp \
    include/libnest2d/optimizers/nlopt/nlopt_boilerplate.hpp \
    include/libnest2d/optimizers/nlopt/simplex.hpp \
    include/libnest2d/optimizers/nlopt/subplex.hpp \
    include/libnest2d/optimizers/optimlib/particleswarm.hpp \
    include/libnest2d/parallel.hpp \
    include/libnest2d/placers/bottomleftplacer.hpp \
    include/libnest2d/placers/nfpplacer.hpp \
    include/libnest2d/placers/placer_boilerplate.hpp \
    include/libnest2d/selections/djd_heuristic.hpp \
    include/libnest2d/selections/filler.hpp \
    include/libnest2d/selections/firstfit.hpp \
    include/libnest2d/selections/selection_boilerplate.hpp \
    include/libnest2d/utils/bigint.hpp \
    include/libnest2d/utils/boost_alg.hpp \
    include/libnest2d/utils/metaloop.hpp \
    include/libnest2d/utils/rational.hpp \
    include/libnest2d/utils/rotcalipers.hpp \
    include/libnest2d/utils/rotfinder.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

LIBS +=	-L$$PWD/clipper/ -lpolyclipping \
        -L$$PWD/nlopt/ -lnlopt

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    how_to_install.txt
