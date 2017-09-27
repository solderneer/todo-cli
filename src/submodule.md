# Subsystem planning

## Display
* Display OBJECT
* 2 windows
* Top bar
    * todo-cli version number
    * Current date and time
    * priority level (color-coding)
    * Fully filled
    * Some debugging information
* Method types
    * DisplayInit(void)
    * DisplayDeInit(void)
    * UpdateTime(string Time)
    * DisplayElementAdd(DisplayElement\* element, WindowType win)
    * setWinTitle(string Name, WindowType win)

## User Interface
* Main loop and associated functions
* Need to manipulate the display object
* Need to pull data from the database

