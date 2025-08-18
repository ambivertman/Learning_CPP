#include <iostream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
using namespace std;
using namespace log4cpp;

void test(){
    OstreamAppender * ap1 = new OstreamAppender("console", &cout);
    ap1->setLayout(new BasicLayout());
    Category & root = Category::getRoot();
    root.setAppender(ap1);
    root.setPriority(Priority::DEBUG);
    root.debug("this is a debug log");
    root.warn("this is a warn log");
    root.alert("this is an alert log");
    Category::shutdown();

}

void test2(){
    FileAppender *ap1 = new FileAppender("file", "appender.log");
    ap1->setLayout(new BasicLayout());

    Category & root = Category::getRoot();
    root.setAppender(ap1);
    root.setPriority(Priority::WARN);

    root.debug("this is a debug log");
    root.warn("this is a warn log");
    root.alert("this is an alert log");
    Category::shutdown();
}

void test3(){
    OstreamAppender *ap1 = new OstreamAppender("console", &cout);
    ap1->setLayout(new BasicLayout());

    FileAppender *ap2 = new FileAppender("file", "appender.log");
    ap2->setLayout(new BasicLayout());

    Category & root = Category::getRoot();
    root.addAppender(ap1);
    root.addAppender(ap2);
    root.setPriority(Priority::WARN);
    
    root.debug("this is a debug log");
    root.warn("this is a warn log");
    root.alert("this is an alert log");
    Category::shutdown();

}

void test4(){
    RollingFileAppender *ap1 = new RollingFileAppender("roll",
                                "roll.log", 500, 9);

    ap1->setLayout(new BasicLayout());

    Category & root = Category::getRoot();
    root.setAppender(ap1);
    root.setPriority(Priority::DEBUG);

    for(int i=0; i < 1000; ++i){
        root.debug("this is a debug log"+to_string(i));
        root.warn("this is a warn log"+to_string(i));
        root.alert("this is an alert log"+to_string(i));
    }
    Category::shutdown();
}




int main(){
    test4();


    return 0;
}

