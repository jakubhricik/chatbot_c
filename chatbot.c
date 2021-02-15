#include "chatbot.h"
#include "database.h"

#define SHORT_ANSWER 3
#define NORMAL_ANSWER 11

const char *input_pos;

int main(int argc, char *argv[]){

    srand(time(NULL));
    char input[MAX_INPUT_SIZE];

    //print generic welcome sentence
    generic_welcome();

    //loop of chat
    while(1){
        printf("> ");
        //geting input
        fgets(input, sizeof(input), stdin);

        //if user type "bye" or "quit" it will generate random message and quit
        if(strnstr(input, "bye", MAX_INPUT_SIZE) == input || strnstr(input, "quit", MAX_INPUT_SIZE) == input){
            generic_quit();
            return 0;
        }
        else answer(input);
    }

    return 0;
}


/*====================
generic quit answer
====================*/
void generic_quit(){
    static const char *messagess[] = {
        "Goodbye.  It was nice talking to you.",
        "Goodbye.  This was really a nice talk.",
        "Goodbye.  I'm looking forward to our next session.",
        "This was a good session, wasn't it -- but time is over now.   Goodbye.",
        "Maybe we could discuss this moreover in our next session ?   Goodbye."
    };
    int random = rand() % 5;
    puts(messagess[random]);
}

/*====================
generic welcome answer
====================*/
void generic_welcome(){
    static const char *messagess[] = {
        "How are you this beautiful day?",
        "How do you do.  Please tell me your problem.",
        "Please tell me what's been bothering you.",
        "Is something troubling you ?"
    };
    int random = rand() % 4;
    puts(messagess[random]);
}

/*====================
generic response
====================*/
void generic_response(){
    static const char *messagess[] = {
        "Did you have a happy childhood?",
        "Did you hate your father?",
        "Did you have a good friend?",
        "Did you like your friend?",
        "What do you think about your friendship?",
        "I'm not sure I understand.",
    };
    int random = rand() % 6;
    puts(messagess[random]);
}


/*====================
Handle answer
====================*/
const char *make_answer(const char *token){
    int random = rand()%4;

    if(strcmp(token, "sorry" ) == 0) return sorry[random];
    else if(strcmp(token, "apologise" ) == 0) return sorry[random];
    else if(strcmp(token, "remember" ) == 0) return remember[random]; 
    else if(strcmp(token, "recall" ) == 0) return remember[random]; 
    else if(strcmp(token, "forget" ) == 0) return forget[random]; 
    else if(strcmp(token, "dreamed" ) == 0) return dreamed[random]; 
    else if(strcmp(token, "dream" ) == 0) return dream[random]; 
    else if(strcmp(token, "perhaps" ) == 0) return perhaps[random]; 
    else if(strcmp(token, "maybe" ) == 0) return perhaps[random]; 
    else if(strcmp(token, "name" ) == 0) return name[random]; 
    else if(strcmp(token, "yes" ) == 0) return yes[random]; 
    else if(strcmp(token, "certainly" ) == 0) return yes[random]; 
    else if(strcmp(token, "no" ) == 0) return no[random]; 
    else if(strcmp(token, "what" ) == 0) return what[random]; 
    else if(strcmp(token, "who" ) == 0) return what[random]; 
    else if(strcmp(token, "when" ) == 0) return what[random]; 
    else if(strcmp(token, "where" ) == 0) return what[random]; 
    else if(strcmp(token, "how" ) == 0) return what[random]; 
    else if(strcmp(token, "why" ) == 0) return what[random]; 
    else if(strcmp(token, "because" ) == 0) return because[random]; 
    else if(strcmp(token, "everyone" ) == 0) return everyone[random]; 
    else if(strcmp(token, "everybody" ) == 0) return everyone[random]; 
    else if(strcmp(token, "nobody" ) == 0) return everyone[random]; 
    else if(strcmp(token, "noone" ) == 0) return everyone[random]; 
    else if(strcmp(token, "always" ) == 0) return always[random]; 
    else if(strcmp(token, "alike" ) == 0) return alike[random]; 
    else if(strcmp(token, "like" ) == 0) return alike[random]; 
    else if(strcmp(token, "equivalent" ) == 0) return alike[random]; 
    else if(strcmp(token, "identical" ) == 0) return alike[random]; 
    else if(strcmp(token, "same" ) == 0) return alike[random]; 
    else if(strcmp(token, "different" ) == 0) return different[random]; 
    else if(strcmp(token, "my" ) == 0) return my[random]; 
    else if(strcmp(token, "myself" ) == 0) return my[random]; 
    else if(strcmp(token, "family" ) == 0) return family[random]; 
    else if(strcmp(token, "fater" ) == 0) return family[random]; 
    else if(strcmp(token, "son" ) == 0) return family[random]; 
    else if(strcmp(token, "daughter" ) == 0) return family[random]; 
    else if(strcmp(token, "mum" ) == 0) return family[random]; 
    else if(strcmp(token, "brother" ) == 0) return family[random]; 
    else if(strcmp(token, "sister" ) == 0) return family[random]; 
    else if(strcmp(token, "sis" ) == 0) return family[random]; 
    else if(strcmp(token, "bro" ) == 0) return family[random]; 
    else if(strcmp(token, "grandfather" ) == 0) return family[random]; 
    else if(strcmp(token, "grandmother" ) == 0) return family[random]; 
    else if(strcmp(token, "mother" ) == 0) return family[random]; 
    else if(strcmp(token, "grandparents" ) == 0) return family[random]; 
    else if(strcmp(token, "parents" ) == 0) return family[random]; 
    else if(strcmp(token, "feel" ) == 0) return feel[random];
    else if(strcmp(token, "feeling" ) == 0) return feel[random];
    else if(strcmp(token, "don't" ) == 0) return dont[random]; 
    else if(strcmp(token, "not" ) == 0) return dont[random]; 
    else if(strcmp(token, "cannot" ) == 0) return cannot[random]; 
    else if(strcmp(token, "can't" ) == 0) return cannot[random]; 
    else if(strcmp(token, "computer" ) == 0) return computer[random]; 
    else if(strcmp(token, "machines" ) == 0) return computer[random]; 
    else if(strcmp(token, "machine" ) == 0) return computer[random]; 
    else if(strcmp(token, "god" ) == 0) return god[random]; 
    else if(strcmp(token, "religion" ) == 0) return god[random]; 
    else if(strcmp(token, "religious" ) == 0) return god[random]; 
    else if(strcmp(token, "believe" ) == 0) return god[random]; 

    else return NULL;
}




/*====================
response
====================*/
void answer(char *input){
    //if answer is < 3
    if(strlen(input) < SHORT_ANSWER){
        const char *remembered_text = get_old_line();
        if(remembered_text){
            printf("You just said: %s", remembered_text);
            puts("Tell me more.");
        }
        else{
            generic_response();
        }
        return;
    }

    if(is_remebered(input)){
        puts("Stop repeating yourself!");
        return;
    }

    if (strlen(input) > NORMAL_ANSWER) { 
        remember_line(input);
    }

    input_pos = input;

    while(1){
        const char *token = next_token();
        if(!token) break;
        const char *answer = make_answer(token);

        if(answer){
            puts(answer);
            return;
        }
    }

    if (strlen(input) > NORMAL_ANSWER) {
        puts("It's seem intersting, tell me more ...");
    } else {
        puts("Tell me more ...");
    }
}


/*====================
token make
====================*/
const char *next_token(){
    static char token[MAX_WORD_SIZE];

    char *token_pos = token;

    while(*input_pos && *input_pos <= ' ') input_pos++;

    if(!*input_pos) return NULL;

    //returning puncturetion
    if(strchr(",.;?!", *input_pos)){
        *token_pos ++ = *input_pos ++;
        *token_pos = 0;
        return token;
    }

    //word
    while(*input_pos && !strchr("\n\r.,?;! ", *input_pos)){
        if(token_pos != token + MAX_WORD_SIZE -2){
            *token_pos++ = tolower(*input_pos++);
        }
        else{
            input_pos++;
        }
    }
    *token_pos = 0;
    return token;
}


/*====================
remember
====================*/
char lines [MAX_LINE_COUNT][MAX_INPUT_SIZE];
int enter_index = 0, return_index = 0;

void remember_line(const char *line){
    if (enter_index == MAX_LINE_COUNT) {
        enter_index = 0;
    }
    strncpy(lines[enter_index], line, MAX_INPUT_SIZE);
    ++enter_index;
}

const char *get_old_line() {
    if (enter_index != return_index)  {
        int result = return_index;
        ++return_index;
        if (return_index == MAX_LINE_COUNT) {
            return_index = 0;
        }
        return lines[result];
    }
    return NULL;
}

bool is_remebered(const char *line) {
    for (int index = 0; index < MAX_LINE_COUNT; ++index) {
        if (!strcmp(line, lines[index]))  return true;
    }
    return false;
}



