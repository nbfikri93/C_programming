/*How to implement ATM finite state machine in C with switch case statement by AMLENDRA*/
/*https://aticleworld.com/state-machine-using-c/*/
/*Edited by me to add functionality to ReadEvent function*/

#include <stdio.h>

//Different state of ATM machine
typedef enum
{
    Idle_State,
    Card_Inserted_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
} eSystemState;

//Different type events
typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event
} eSystemEvent;

//Prototype of eventhandlers
eSystemState AmountDispatchHandler(void)
{
    return Idle_State;
}
eSystemState EnterAmountHandler(void)
{
    return Amount_Entered_State;
}
eSystemState OptionSelectionHandler(void)
{
    return Option_Selected_State;
}
eSystemState EnterPinHandler(void)
{
    return Pin_Eentered_State;
}
eSystemState InsertCardHandler(void)
{
    return Card_Inserted_State;
}

eSystemEvent ReadEvent(void)
{
    //the event shall be invoked by the user choice
    //the event can read from the user input such as button/screen touch
    //in this example, we only set the event to the first event
    return Card_Insert_Event;
}

int main(int argc, char *argv[])
{
    eSystemState eNextState = Idle_State;
    eSystemEvent eNewEvent;
    
    while(1)
    {
        //Read system Events
        eSystemEvent eNewEvent = ReadEvent();
        
        switch(eNextState)
        {
            case Idle_State:
            {
                if(Card_Insert_Event == eNewEvent)
                {
                    printf("Please insert your card\n");
                    eNextState = InsertCardHandler();
                }
            }
            break;
            
            case Card_Inserted_State:
            {
                if(Pin_Enter_Event == eNewEvent)
                {
                    printf("Please enter your pin number\n");
                    eNextState = EnterPinHandler();
                }
            }
            break;
            
            case Pin_Eentered_State:
            {
                if(Option_Selection_Event == eNewEvent)
                {
                    printf("Please select the option\n");
                    eNextState = OptionSelectionHandler();
                }
            }
            break;
            
            case Option_Selected_State:
            {
                if(Amount_Enter_Event == eNewEvent)
                {
                    printf("Please enter the amount to withdraw\n");
                    eNextState = EnterAmountHandler();
                }
            }
            break;
            
            case Amount_Entered_State:
            {
                if(Amount_Dispatch_Event == eNewEvent)
                {
                    printf("Amount withdrawing...\n");
                    eNextState = AmountDispatchHandler();
                }
            }
            break;
            
            default:
                break;
        }
    }
    return 0;
}

