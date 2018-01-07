2018 - MatchData
===
This simple library makes it easy to parse the match data in 2018 _FIRST_ POWER UP for both Java and C++.

# Example:
### Java:
```java
@Override
public void autonomousPeriodic() {
    MatchData.OwnedSide side = MatchData.getOwnedSide(MatchData.GameFeature.SWITCH_NEAR);
    if (side == MatchData.OwnedSide.LEFT) {
        // Do something with the left
    } else if (side == MatchData.OwnedSide.RIGHT) {
        // Do something with the right
    } else {
        // Unknown
    }
}
```

### C++:
```cpp
#include <openrio/powerup/MatchData.h>
using namespace OpenRIO::PowerUp;

void AutonomousPeriodic() {
    MatchData::OwnedSide side = MatchData::get_owned_side(MatchData::GameFeature::SWITCH_NEAR);
    if (side == MatchData::OwnedSide::LEFT) {
        // Do something with the left
    } else if (side == MatchData::OwnedSide::RIGHT) {
        // Do something with the right
    } else {
        // Unknown
    }
}
```

NOTE: It is recommended to store the result of `getOwnedSide`/`get_owned_side` on the first successful call to increase performance.

# Download:
## GradleRIO (Recommended):
Use GradleRIO 2017.01.07 or later.

### Java:
```gradle
dependencies {
    compile openrio.powerup.matchData()
}
```

### C++:
```gradle
model {
    components {
        frcUserProgram(NativeExecutableSpec) {
            // ETC //
            lib library: "openrio.powerup.matchData"
        }
    }
}
```

## Eclipse Plugins:
You can find downloads for the files [here](http://dev.imjac.in/maven/openrio/powerup/MatchData/2018.01.07/).

Download MatchData-2018.01.07.jar for Java, and MatchData-2018.01.07-headers.zip for C++. Install as you would any other vendor library.

## Maven:
Repository: http://dev.imjac.in/maven  
Group: openrio.powerup  
Artifact ID: MatchData  

C++ Header Classifier: headers
