/*
This chapter does not say what happens when you run out of memory using new. That’s called memory exhaustion. Find
out what happens. You have two obvious alternatives: look for documentation, or write a program with an infinite loop that
allocates but never deallocates. Try both. Approximately how much memory did you manage to allocate before failing?
*/

void allocate()
{
    int* a=new int[1024];
}

int main()
{
    //memory cost 398.5Mb
    for(int i=0;i<100000;++i)
    {
        allocate();
    }
    return 0;
}