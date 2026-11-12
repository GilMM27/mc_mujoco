#pragma once
#include <array>
#include <cstddef>
#include <string>

namespace smplh_contact
{
inline constexpr const char * datastoreKey = "smplh_contact_forces";
inline constexpr const char * selectionDatastoreKey = "smplh_contact_selection";
inline constexpr std::array<const char *, 14> regions = {
    "torso", "head", "left_upper_arm", "left_forearm", "left_hand",
    "right_upper_arm", "right_forearm", "right_hand", "left_thigh",
    "left_lower_leg", "left_foot", "right_thigh", "right_lower_leg", "right_foot"};
struct Snapshot
{
  bool valid = false;
  double time = 0;
  std::array<double, 14> positiveNormalSumN{};
  std::array<double, 14> peakPositiveNormalSumN{};
  bool externalTorqueFeedback = false;
  bool highPassCompensation = false;
  double externalJointTorqueNormNm = 0;
  bool selectedPointValid = false;
  double selectedPointTime = 0;
  size_t selectedRegion = 0;
  double selectedTorqueForceN = 0;
  double selectedMujocoForceN = 0;
  double selectedForceDifferenceN = 0;
  double selectedContactPointDistanceM = 0;
};
struct Selection
{
  bool valid = false;
  double time = 0;
  size_t region = 0;
  std::string robotBody;
  std::array<double, 3> position{};
  std::array<double, 3> normal{};
};
}
