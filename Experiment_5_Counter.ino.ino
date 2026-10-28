int delay_time = 200;

void setup()
{
    pinMode(12, INPUT_PULLUP);

    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void displayDigit(int digit)
{
    // Common-anode: LOW = ON, HIGH = OFF

    switch (digit)
    {
        case 0:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, HIGH);
            break;

        case 1:
            digitalWrite(1, HIGH);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            break;

        case 2:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            break;

        case 3:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            break;

        case 4:
            digitalWrite(1, HIGH);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            break;

        case 5:
            digitalWrite(1, LOW);
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            break;

        case 6:
            digitalWrite(1, LOW);
            digitalWrite(2, HIGH);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            break;

        case 7:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            break;

        case 8:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            break;

        case 9:
            digitalWrite(1, LOW);
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            break;
    }
}

void loop()
{
    static int count = 0;

    if (digitalRead(12) == LOW)
    {
        displayDigit(count);

        delay(200);

        count++;

        if (count > 9)
        {
            count = 0;
        }

        // Wait for button release
        while (digitalRead(12) == LOW)
        {
            delay(10);
        }
    }
}