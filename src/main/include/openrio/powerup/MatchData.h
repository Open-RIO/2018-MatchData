#pragma once

#include <cstdint>
#include <string>
#include <DriverStation.h>

namespace OpenRIO {
namespace PowerUp {
  /**
   * The MatchData class provides an easy interface to the 2018 Match Data
   * sent by the FMS and DS to indicate the configuration of the SWITCH
   * and SCALE
   *
   * \author Jaci Brunning
   */
  class MatchData {
  public:

    /**
     * Game features including the SWITCH and SCALE. Near denotes close
     * to the alliance wall and FAR denotes furthest from the alliance 
     * wall
     */
    enum class GameFeature : uint8_t {
      SWITCH_NEAR = 0,
      SCALE = 1,
      SWITCH_FAR = 2
    };

    /**
     * OwnedSide defines which side (from the perspective of the alliance
     * station) is owned by the alliance during the match. This is one of
     * LEFT, RIGHT or UNKNOWN (the latter in the case where game data
     * is not yet made available by the FMS or DS)
     */
    enum class OwnedSide : uint8_t {
      UNKNOWN = 0,
      LEFT = 1,
      RIGHT = 2
    };

    /**
     * Determine the OwnedSide of any given GameFeature. Use this method to
     * determine which PLATE of each feature (SCALE or SWITCH) is OWNED by your
     * ALLIANCE. Perspectives are referenced relative to your ALLIANCE STATION.
     *
     * \arg \c feature The feature to get the owned side for. See GameFeature.
     * \return  The Owned Side (PLATE) of the feature. See OwnedSide. Make sure to
     *          check for UNKNOWN.
     */
    static OwnedSide get_owned_side(const GameFeature feature) {
      std::string gsm = frc::DriverStation::GetInstance().GetGameSpecificMessage();
      if (gsm.length() < 3)
        return OwnedSide::UNKNOWN;

      uint8_t index = static_cast<uint8_t>(feature);
      if (index >= 3 || index < 0)
        return OwnedSide::UNKNOWN;

      char gd = gsm[index];
      switch (gd) {
      case 'L':
      case 'l':
        return OwnedSide::LEFT;
      case 'R':
      case 'r':
        return OwnedSide::RIGHT;
      default:
        return OwnedSide::UNKNOWN;
      }
    }

    /**
     * Get the name of a GameFeature as a std::string.
     */
    static std::string get_feature_name(const GameFeature feature) {
      switch (feature) {
      case GameFeature::SWITCH_NEAR:
        return "SWITCH_NEAR";
      case GameFeature::SCALE:
        return "SCALE";
      case GameFeature::SWITCH_FAR:
        return "SWITCH_FAR";
      }
    }

    /**
     * Get the name of an OwnedSide as a std::string.
     */
    static std::string get_owned_side_name(const OwnedSide side) {
      switch (side) {
      case OwnedSide::LEFT:
        return "LEFT";
      case OwnedSide::RIGHT:
        return "RIGHT";
      default:
        return "UNKNOWN";
      }
    }
  };
} // ns PowerUp
} // ns OpenRIO