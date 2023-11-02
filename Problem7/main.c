const int piezo = 7;

char code[] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };
int melody[] = { 262, 294, 330, 349, 392, 440, 494, 523 };
char beat[] = "4222244222243122224422224";
char music_core[] = "GEEGECDEDCEGCGCGCGEGDFEDC";
const int mSize = sizeof(beat);

void setup()
{
	pinMode(piezo, OUTPUT);
}

void loop()
{
	for (int i = 0; i < mSize; ++i)
	{
		for (int k = 0; k < 7; ++k)
		{
			if (music_core[i] == code[k])
			{
				int play_time = (beat[i] - '0') * 100;
				tone(piezo, melody[k], play_time);
				delay(play_time);
			}
		}
	}
	noTone(piezo);
	return 0;
}