#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>

class DisplayObject
{
    public:
        DisplayObject();
        ~DisplayObject();
    private:
        WINDOW* displaywin;
}

class TopBar: public DisplayObject()
{
    public:
        ~TopBar();

        void updateTimeStamp(void);
        int getTimeStamp(void);
        static TopBar* instance();
    private:
        WINDOW* topbarwin;
        static TopBar *s_instance;
        TopBar();
};
