package openrio.powerup;

import edu.wpi.first.wpilibj.DriverStation;

/**
 * The MatchData class provides an easy interface to the 2018 Match Data
 * sent by the FMS and DS to indicate the configuration of the SWITCH
 * and SCALE.
 *
 * @author Jaci Brunning
 */
public class MatchData {

    /**
     * Game features including the SWITCH and SCALE. Near denotes close
     * to the alliance wall and FAR denotes furthest from the alliance
     * wall
     */
    public static enum GameFeature {
        SWITCH_NEAR, SCALE, SWITCH_FAR
    }

    /**
     * OwnedSide defines which side (from the perspective of the alliance
     * station) is owned by the alliance during the match. This is one of
     * LEFT, RIGHT or UNKNOWN (the latter in the case where game data
     * is not yet made available by the FMS or DS)
     */
    public static enum OwnedSide {
        UNKNOWN, LEFT, RIGHT
    }

    /**
     * Determine the OwnedSide of any given GameFeature. Use this method to
     * determine which PLATE of each feature (SCALE or SWITCH) is OWNED by your
     * ALLIANCE. Perspectives are referenced relative to your ALLIANCE STATION.
     *
     * @param feature The feature to get the owned side for. See GameFeature.
     * @return  The Owned Side (PLATE) of the feature. See OwnedSide. Make sure to
     *          check for UNKNOWN.
     */
    public static OwnedSide getOwnedSide(GameFeature feature) {
        String gsm = DriverStation.getInstance().getGameSpecificMessage();
        if (gsm == null)
            return OwnedSide.UNKNOWN;

        // If the length is less than 3, it's not valid. Longer than 3 is permitted, but only
        // the first 3 characters are taken.
        if (gsm.length() < 3)
            return OwnedSide.UNKNOWN;

        int index = feature.ordinal();
        // Theoretically this should never happen, but it's good to be safe.
        if (index >= 3 || index < 0)
            return OwnedSide.UNKNOWN;

        char gd = gsm.charAt(index);
        switch (gd) {
            case 'L':
            case 'l':
                return OwnedSide.LEFT;
            case 'R':
            case 'r':
                return OwnedSide.RIGHT;
            default:
                return OwnedSide.UNKNOWN;
        }
    }
}
