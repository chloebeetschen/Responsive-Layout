//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>
//scroll bar includes
#include <QScrollArea>
#include <QScrollBar>


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);

    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();

    // add all the widgets we need to demonstrate all layouts
    // we might have more than one search results
    // note that later widgets are drawn on top of earlier widgets

    //widgets for main window
    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    rl->addWidget(new ResponsiveLabel(kMenu));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kSearchText));
    rl->addWidget(new ResponsiveLabel(kWishList));
    rl->addWidget(new ResponsiveLabel(kHelp));
    rl->addWidget(new ResponsiveLabel(kSearchOptions));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kSearchBackward));
    rl->addWidget(new ResponsiveLabel(kSearchForward));

    //scroll area
    //make a new scroll area
    QScrollArea *scrollArea = new QScrollArea();
    //make a widget that will go into the scroll area
    QWidget *resultsWidget = new QWidget();
    //make a new responsive layout that will go into the widget (that's in the scroll area)
    ResponsiveLayout * rSearch = new ResponsiveLayout();

    //can be changed based on number of results inputting
    int resultNum = 17;
    //add number of widgets entered in resultsNum into the responsive layour
    for(int i = 0; i < resultNum; i ++){
        rSearch->addWidget(new ResponsiveLabel(kSResultImage));
        rSearch->addWidget(new ResponsiveLabel(kSResultText));
    }
    //set the new widget's layout to our new layout
    resultsWidget->setLayout(rSearch);
    //set the new widget to the scroll area
    scrollArea->setWidget(resultsWidget);
    //add the scroll area into our main layout
    rl->addWidget(scrollArea);

    //set the main layout
    setLayout(rl);
}


