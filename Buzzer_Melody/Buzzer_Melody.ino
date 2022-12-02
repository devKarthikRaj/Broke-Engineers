/**
 * Load and play an RTTTL melody from hardcoded literal string
 */
#include <melody_player.h>
#include <melody_factory.h>

int buzzerPin = 15;

const char topGunMelody[] = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
const char missionImpMelody[] = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";      
const char starWarsMelody[] = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";

MelodyPlayer player(buzzerPin);

void setup() {
  Serial.begin(115200);

  //This is just to make sure that Serial is setup before Serial.print-ing
  while (!Serial)
    ;

  Serial.println();
  Serial.println("Melody Player - Load RTTTL melody");

  Serial.print("Loading hardcoded melody... ");
  Melody melody = MelodyFactory.loadRtttlString(missionImpMelody);
  if (melody) {
    Serial.println("Done!");
    Serial.print("Playing ");
    Serial.print(melody.getTitle());
    Serial.print("... ");
    player.play(melody);
    Serial.println("Done!");
  } else {
    Serial.println("Error");
  }

  delay(1000);
  Serial.println();

}

void loop() {}
