#ifndef FONT3x5_H
#define FONT3x5_H

#include <Arduino.h>
#include <Print.h>

class Font3x5 : public Print {
    
  public:

    Font3x5(int16_t width, int16_t height);   

    virtual size_t write(uint8_t); // used by the Arduino Print class

    /** \brief
     * Prints a single letter in ASCII range from 65 - 90 (A-Z) and 48 - 57 (0-9)
     *
     * \details
     * Every character outside the range will be a blank.
     */
    void printChar(char c, int16_t x, int16_t y);


    /** \brief
     * Set the location of the text cursor.
     *
     * \param x The X coordinate, in pixels, for the new location of the text cursor.
     * \param y The Y coordinate, in pixels, for the new location of the text cursor.
     *
     * \details
     * The location of the text cursor is set the the specified coordinates.
     * The coordinates are in pixels. Since the coordinates can specify any pixel
     * location, the text does not have to be placed on specific rows.
     * As with all drawing functions, location 0, 0 is the top left corner of
     * the display. The cursor location will be the top left corner of the next
     * character written.
     */
    void setCursor(int16_t x, int16_t y);

    /** \brief
     * Get the X coordinate of the current text cursor position.
     *
     * \return The X coordinate of the current text cursor position.
     *
     * \details
     * The X coordinate returned is a pixel location with 0 indicating the
     * leftmost column.
     */
    const int16_t getCursorX();

    /** \brief
     * Get the Y coordinate of the current text cursor position.
     *
     * \return The Y coordinate of the current text cursor position.
     *
     * \details
     * The Y coordinate returned is a pixel location with 0 indicating the
     * topmost row.
     */
    const int16_t getCursorY();

    /** \brief
     * Set the text foreground color.
     *
     * \param color The color to be used for following text.
     */
    void setTextColor(uint8_t color);


  private:

    int16_t sWidth;
    int16_t sHeight;

    int16_t cursorX;    //!< Default is 0.
    int16_t baseX;      //!< needed for linebreak.
    int16_t cursorY;    //!< Default is 0.

    int16_t textColor;  // BLACK == 0, everything else is WHITE. Default is WHITE.

    uint8_t letterSpacing;  //!< letterSpacing controls the distance between letters. Default is 1.
    uint8_t lineHeight;     //!< lineHeight controls the height between lines breakend by \n. Default is 6.

};

#endif
