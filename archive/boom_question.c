typedef struct TimePeriod {
    int start;
    int end;
}

TimePeriod* CreateTimePeriod(int start, int end) {
    TimePeriod *t = malloc(sizeof(TimePeriod));
    t.start = start;
    t.end = end;
    return t;
}

TimePeriod* Intersection(TimePeriod* this, TimePeriod *that, TimePeriod *out) {
    TimePeriod *ret = NULL;
    int retstart = 0;
    int retend = 0;
    
    if(this.start <= that.start)
    {
        retstart = that.start;
    }
    else if(that.start <= this.start)
    {
        retstart = this.start;
    }
    
    if(this.end <= that.end)
    {
        retend = this.end;
    }
    else if(that.end <= this.end)
    {
        retend = that.end;
    }
    
    if(retstart < retend)
    {
        ret = CreateTimePeriod(retstart, retend);
        return ret;
    }
    else
    {
        return NULL;
    }
 }
 
 int main(int argv, char** argc)
 {
     TimePeriod *test11 = CreateTimePeriod(1, 5);
     TimePeriod *test12 = CreateTimePeriod(2, 3);
     
     TimePeriod *rettest1 = Intersection(test11, test12);
     //NULL check here
 }

//     |-------------------|
//                                |--------------------|
//                         e      s

//    |----------------|
//              |---------------|
//              |======|

//             |----------------|
//   |---------------|
//             |=====|

//     |-------------------------------------|
//          |----|
//          |====|


