#ifndef CREW_UI_H
#define CREW_UI_H

#include "gui/mainUIBase.h"
#include "playerInfo.h"
#include "spaceObjects/spaceship.h"
#include "repairCrew.h"

class CrewUI : public MainUIBase
{
private:
    float return_to_ship_selection_time;
public:
    CrewUI();

    virtual void onGui();
    virtual void onCrewUI();

    /**!
     * \brief Draw a freqency curve.
     * \param rect Rectangle
     * \param text_size
     */
    void drawImpulseSlider(sf::FloatRect rect, float text_size);

    /**!
     * \brief Draw the slider for warp drive.
     * \param rect Rectangle
     * \param text_size
     */
    void drawWarpSlider(sf::FloatRect rect, float text_size);

    /**!
     * \brief Draw the slider for jump drive.
     * \param jump_distance
     * \param rect Rectangle
     * \param text_size
     */
    void drawJumpSlider(float& jump_distance, sf::FloatRect rect, float text_size);

    /**!
     * \brief Draw activation button for jump drive.
     * \param jump_distance
     * \param rect Rectangle
     * \param text_size
     */
    void drawJumpButton(float jump_distance, sf::FloatRect rect, float text_size);

    /**!
     * \brief Draw activation button for docking.
     * \param rect Rectangle
     * \param text_size
     */
    void drawDockingButton(sf::FloatRect rect, float text_size);

    /**!
     * \brief Draw a weapon tube.
     * \param rect Rectangle
     * \param text_size
     */
    void drawWeaponTube(EMissileWeapons load_type, int n, float missile_target_angle, sf::FloatRect load_rect, sf::FloatRect fire_rect, float text_size);

    /**!
     * \brief Draw a freqency curve.
     * \param more_damage_is_positive True for weapons, false for shielding
     */
    int drawFrequencyCurve(sf::FloatRect rect, bool frequency_is_beam, bool more_damage_is_positive, int frequency);

    /**!
     * Draw state of system. (Jammed, no power, broken, etc)
     */
    void drawDamagePowerDisplay(sf::FloatRect rect, ESystem system, float text_size);

    /**!
     * Draw on screen keyboard.
     */
    string drawOnScreenKeyboard();

    /**!
     * Calculate the firing angle to hit the chosen target position.
     * Returns the absolute firing angle, or std::numeric_limits<float>::infinity() when no solution is found.
     */
    float calculateFiringSolution(sf::Vector2f target_position);
    
    void drawMissileTrajectory(sf::Vector2f radar_center, float radar_size, float radar_distance, float missile_target_angle);
    void drawTargetTrajectory(sf::Vector2f radar_center, float radar_size, float radar_distance, P<SpaceObject> target);
};

#endif//CREW_UI_H
