// External vars
extern const int ENTRIES;
extern char command;
extern double first, last, delta;

// Required function prototypes
void initialize();

bool checkCode (char);

void writeDataToFile(const char *);

void readDataFromFile(const char *);

int factorial(int);

int fibonacci(int);

double findSqrtValue(double);

double naturalLog(double);

double areaCircle(double);

double areaSquare(double);

int findNextOddValue(int);

int findNextEvenValue(int);

double findNyanCatValue(double);

double doMath(double, char);

double lucky(double);

// Extra function prototypes
char selectCommand();

bool checkInput();