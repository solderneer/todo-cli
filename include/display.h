#ifndef DISPLAY_H
#define DISPLAY_H

class TopBar
{
    private:
        WINDOW* topWin;
        static TopBar* s_instance;
        TopBar();

    public:
        ~TopBar();
        void updateTimeStamp(void);
        int getTimeStamp(void);
        static TopBar* instance();
}

class LeftWin
{
    private:
        WINDOW leftWin;
        static LeftWin* s_instance;
        LeftWin();

    public:
        ~LeftWin();
        static LeftWin* instance();
}

class RightWin
{
    private:
        WINDOW* rightWin;
        static RightWin* s_instance;
        RightWin();

    public:
        ~RightWin();
        static RightWin* s_instance;
}
#endif /*DISPLAY_H*/
