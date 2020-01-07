int maxLine = 0;
int currentLine = 0;
int lineBlock = 0;
int star = 0;
int totalStar = 1;
int removeStar = 1;
int space = 0;
int addSpace = 1;
int totalSpace = 0;
int lineTrunc = 0;
int pipe = 0;
int maxChar;

void max_chars(int size)
{
    int i;

    maxChar = 7;
    for (i = 1; i < size; ++i) {
        maxChar = maxChar + i + 1 + 4 + (i+1)%2;
    }
}

void print_tree(int value) {
    int block = value;

    totalSpace = ( maxChar - 1 ) /2;
    for (block; block > 0; --block) {
        maxLine += block + 3;
    }
    block = 1;
    for (currentLine = 0; currentLine < maxLine; ++currentLine) {
        lineBlock = 0;
        for (lineBlock; lineBlock < block + 3; ++lineBlock) {
            draw_star_and_space();
        }
        ++block;
        if (block%2 != 1) {
            ++removeStar;
            ++addSpace;
        }
        totalStar -= removeStar * 2;
        totalSpace += addSpace;
    }
}

void draw_star_and_space(void)
{
    for (star; star < totalStar; ++star) {
        for (space; space < totalSpace; ++space) {
            my_putchar(32);
        }
        my_putchar(42);
    }
    my_putchar(10);
    totalStar = star + 2;
    totalSpace = space - 1;
    star = 0;
    space = 0;
    ++currentLine;
}

void print_trunc(int value)
{
    space = 0;
    totalSpace = ( maxChar - value ) / 2;
    for (lineTrunc; lineTrunc < value; ++lineTrunc) {
        for (space; space < totalSpace; ++space) {
            my_putchar(32);
        }
        if (value%2 == 0) {
            --pipe;
        }
        for (pipe; pipe < value; ++pipe) {
            my_putchar(124);
        }
        space = 0;
        pipe = 0;
        my_putchar(10);
    }
}

int tree(int size)
{
    if (size > 0) {
        max_chars(size);
        print_tree(size);
        print_trunc(size);
    }
    return (0);
}
