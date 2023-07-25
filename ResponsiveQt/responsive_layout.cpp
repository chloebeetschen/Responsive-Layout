//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>
//scroll bar includes
#include <QScrollArea>
#include <QScrollBar>

//using namespace std;

// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {

    QLayout::setGeometry(r);

    //padding - been added to all geometry coordinates to make margins between labels
    int padding = 3;
    //counter for result images
    int resultCountI = 0;
    //counter for results texts
    int resultCountT = 0;

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {
        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            //make QScrollBar and dynamically cast it
            QScrollArea *scrollArea = dynamic_cast<QScrollArea *>(o->widget());
            //make sure it isn't null
            if(scrollArea != nullptr){
                //set the scroll area size on the screen and the widget inside the scroll area size for all window sizes
                if(r.height() < r.width()){
                    scrollArea -> widget() -> setGeometry(0, 0, 3*(r.width()/5)-(7*padding), 1700+padding);
                    scrollArea -> setGeometry((r.width()/5)+padding, 80+padding, r.width()-2*(r.width()/5)-padding, r.height()-130);
                }else if(r.height() == 320 && r.width() == 320){
                    scrollArea -> widget() -> setGeometry(0, 0, r.width()-(8*padding), 1700+padding);
                    scrollArea -> setGeometry(padding, 80+padding, r.width()-2*(padding), r.height()-130);
                }else {
                    scrollArea -> widget() -> setGeometry(0, 0, r.width()-(8*padding), 1700+padding);
                    scrollArea -> setGeometry(padding, 120+padding, r.width()-2*(padding), r.height()-212);
                }
                continue;
            }

            //compact layour (320x320)
            if(r.height() == 320 && r.width() == 320){

                if (label == NULL) // null: cast failed on pointer
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                //header
                else if(label -> text() == kMenu)
                    label -> setGeometry(padding,padding,(r.width()/6)-padding, 40-padding);
                else if(label -> text() == kHomeLink)
                    label -> setGeometry((r.width()/6)+padding,padding,(4*(r.width()/6))-(2*padding), 40-padding);
                else if(label -> text() == kShoppingBasket)
                    label -> setGeometry((r.width()-r.width()/6),padding,(r.width()/6)-padding, 40-padding);
                //row 2
                else if(label -> text() == kNavTabs )
                    label -> setGeometry(padding,40+padding, (r.width()/2)-padding, 40-padding);
                else if(label -> text() == kSearchText)
                    label -> setGeometry((r.width()/2)+padding, 40+padding, (r.width()/3)-(2*padding), 40-padding);
                else if(label -> text() == kSearchButton)
                    label -> setGeometry(r.width()-r.width()/6, 40+padding, (r.width()/6)-padding, 40-padding);
                //main body
                    //center of main body
                        //results don't need to be indented as much as other items as they are relative to the scroll area not the window
                else if(label -> text() == kSResultImage){
                    label -> setGeometry(padding,padding+(resultCountI*100),(r.width()/2)-(2*padding), 100-padding);
                    resultCountI++;
                }else if(label -> text() == kSResultText){
                    label -> setGeometry(r.width()/2,padding+(resultCountT*100),r.width()/2-(2*padding), 100-padding);
                    resultCountT++;
                    //footer of main body
                }else if(label -> text() == kHelp)
                    label -> setGeometry((r.width()/4)+padding,(r.height()-40)-padding,(r.width()/2)-padding, 40-padding);
                else if(label -> text() == kSearchBackward)
                    label -> setGeometry((r.width()/8)-padding,(r.height()-40)-padding,r.width()/8, 40-padding);
                else if(label -> text() == kSearchForward)
                    label -> setGeometry((r.width()-r.width()/4)+padding,(r.height()-40)-padding,(r.width()/8), 40-padding);


                // otherwise: disappear label by moving out of bounds
                else
                    label -> setGeometry (-1,-1,0,0);


            //vertical layout
            }else if(r.height() >= r.width()){

                if (label == NULL) // null cast failed on pointer
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                //header
                else if(label -> text() == kMenu)
                    label -> setGeometry(padding,padding,(r.width()/6)-padding, 40-padding);
                else if(label -> text() == kHomeLink)
                    label -> setGeometry((r.width()/6)+padding,padding,(4*(r.width()/6))-(2*padding), 40-padding);
                else if(label -> text() == kSignIn)
                    label -> setGeometry((r.width()-r.width()/6),padding,(r.width()/6)-padding, 40-padding);
                //row 2
                else if(label -> text() == kNavTabs )
                    label -> setGeometry(padding,40+padding, (r.width()/2)-padding, 40-padding);
                else if(label -> text() == kWishList)
                    label -> setGeometry((r.width()-r.width()/2)+padding,40+padding,(r.width()/4)-(2*padding), 40-padding);
                else if(label -> text() == kShoppingBasket)
                    label -> setGeometry((r.width()-r.width()/4),40+padding,(r.width()/4)-padding, 40-padding);
                //row 3
                else if(label -> text() == kSearchOptions)
                    label -> setGeometry(padding,80+padding,(r.width()/2)-padding, 40-padding);
                else if(label -> text() == kSearchText)
                    label -> setGeometry((r.width()/2)+padding, 80+padding, (r.width()/3)-(2*padding), 40-padding);
                else if(label -> text() == kSearchButton)
                    label -> setGeometry(r.width()-r.width()/6, 80+padding, (r.width()/6)-(2*padding), 40-padding);
                //main body
                    //center of main body
                        //results don't need to be indented as much as other items as they are relative to the scroll area not the window
                else if(label -> text() == kSResultImage){
                    label -> setGeometry(padding,padding+(resultCountI*100),(r.width()/2)-(2*padding), 100-padding);
                    resultCountI++;
                }else if(label -> text() == kSResultText){
                    label -> setGeometry(r.width()/2,padding+(resultCountT*100),r.width()/2, 100-padding);
                    resultCountT++;
                    //footer of main body
                }else if(label -> text() == kHelp)
                    label -> setGeometry((r.width()/4)+padding,(r.height()-80)-padding,(r.width()/2)-padding, 40-padding);
                else if(label -> text() == kSearchBackward)
                    label -> setGeometry((r.width()/8)-padding,(r.height()-80)-padding,r.width()/8, 40-padding);
                else if(label -> text() == kSearchForward)
                    label -> setGeometry((r.width()-r.width()/4)+padding,(r.height()-80)-padding,(r.width()/8), 40-padding);
                else if(label -> text() == kAdvert)
                    label -> setGeometry(padding,(r.height()-40)-padding,r.width()-(2*padding), 40-padding);


                // otherwise: disappear label by moving out of bounds
                else
                     label -> setGeometry (-1,-1,0,0);


            //horizontal layout
            }else{

                if (label == NULL) // null: cast failed on pointer
                    std::cout << "warning, unknown widget class in layout" << std::endl;
                //header
                else if(label -> text() == kMenu)
                    label -> setGeometry(padding,padding,(r.width()/8)-padding, 40-padding);
                else if(label -> text() == kHomeLink)
                    label -> setGeometry((r.width()/8)+padding,padding,(3*(r.width()/8))-(2*padding), 40-padding);
                else if(label -> text() == kSignIn)
                    label -> setGeometry(r.width()-r.width()/2,padding,(r.width()/6)-padding, 40-padding);
                else if(label -> text() == kWishList)
                    label -> setGeometry(r.width()-r.width()/3,padding,(r.width()/6)-padding, 40-padding);
                else if(label -> text() == kShoppingBasket)
                    label -> setGeometry(r.width()-r.width()/6,padding,(r.width()/6)-padding, 40-padding);
                //row 2
                else if(label -> text() == kNavTabs )
                    label -> setGeometry(padding,40+padding, (r.width()/2)-(1.5*padding), 40-padding);
                else if(label -> text() == kSearchText)
                    label -> setGeometry((r.width()/2), 40+padding, (4*(r.width()/10))-padding, 40-padding);
                else if(label -> text() == kSearchButton)
                    label -> setGeometry(r.width()-r.width()/10, 40+padding, (r.width()/10)-padding, 40-padding);
                //main body
                    //left side of main boday
                else if(label -> text() == kSearchOptions)
                    label -> setGeometry(padding,80+padding,(r.width()/5)-padding, r.height()-85);
                    //center of main body
                        //results don't need to be indented as much as other items as they are relative to the scroll area not the window
                else if(label -> text() == kSResultImage){
                    label -> setGeometry(padding,padding+(resultCountI*100),(r.width()/2)-(2*padding), 100-padding);
                    resultCountI++;
                }else if(label -> text() == kSResultText){
                    label -> setGeometry(r.width()/2,padding+(resultCountT*100),r.width()/2-(2*padding), 100-padding);
                    resultCountT++;
                    //footer of main body
                }else if(label -> text() == kHelp)
                    label -> setGeometry(2*(r.width()/5)+padding,(r.height()-40)-padding,(r.width()/5)-padding, 40-padding);
                else if(label -> text() == kSearchBackward)
                    label -> setGeometry((2*(r.width()/5)-r.width()/10),r.height()-40-padding,r.width()/10, 40-padding);
                else if(label -> text() == kSearchForward)
                    label -> setGeometry(r.width()-2*(r.width()/5),r.height()-40-padding,r.width()/10, 40-padding);
                    //right side of main body
                else if(label -> text() == kAdvert)
                    label -> setGeometry((r.width()-r.width()/5)+padding,80+padding,(r.width()/5)-(2*padding), r.height()-85);


                // otherwise: disappear label by moving out of bounds
                else
                     label -> setGeometry (-1,-1,0,0);

            }
        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}

// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
