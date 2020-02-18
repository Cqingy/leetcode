int rectCover(int number) {
    if(number == 0) return 0;
    if(number == 1) return 1;
    if(number == 2) return 2;
    int first = 1;
    int second = 2;
    for(int i = 3; i <= number; i++) {
        int temp = first;
        first = second;
        second = second + temp;
    }
    return second;
}