/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made
 *to this file will be overwritten if the respective MCUXpresso Config Tools is
 *used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
    #define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

    #if defined( __cplusplus )
extern "C" {
    #endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins( void );

    #define IOCON_PIO_DIGITAL_EN                                      \
        0x0100u                   /*!<@brief Enables digital function \
                                   */
    #define IOCON_PIO_FUNC1 0x01u /*!<@brief Selects pin function 1 */
    #define IOCON_PIO_INV_DI                            \
        0x00u /*!<@brief Input function is not inverted \
               */
    #define IOCON_PIO_MODE_INACT   0x00u /*!<@brief No addition pin function */
    #define IOCON_PIO_OPENDRAIN_DI 0x00u /*!<@brief Open drain is disabled */
    #define IOCON_PIO_SLEW_STANDARD \
        0x00u /*!<@brief Standard mode, output slew rate control is enabled */
    #define PIO1_4_DIGIMODE_DIGITAL                                         \
        0x01u /*!<@brief Select Digital mode.: Enable Digital mode. Digital \
                 input is enabled. */
    #define PIO1_4_FUNC_ALT0 \
        0x00u /*!<@brief Selects pin function.: Alternative connection 0. */
    #define PIO1_6_DIGIMODE_DIGITAL                                         \
        0x01u /*!<@brief Select Digital mode.: Enable Digital mode. Digital \
                 input is enabled. */
    #define PIO1_6_FUNC_ALT0 \
        0x00u /*!<@brief Selects pin function.: Alternative connection 0. */
    #define PIO1_7_DIGIMODE_DIGITAL                                         \
        0x01u /*!<@brief Select Digital mode.: Enable Digital mode. Digital \
                 input is enabled. */
    #define PIO1_7_FUNC_ALT0 \
        0x00u /*!<@brief Selects pin function.: Alternative connection 0. */
    #define PIO1_9_DIGIMODE_DIGITAL                                         \
        0x01u /*!<@brief Select Digital mode.: Enable Digital mode. Digital \
                 input is enabled. */
    #define PIO1_9_FUNC_ALT0 \
        0x00u /*!<@brief Selects pin function.: Alternative connection 0. */

    /*! @name PIO0_29 (number 92), UART_RX
      @{ */
    #define BOARD_INITPINS_UART_RX_PORT \
        0U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_UART_RX_PIN 29U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_UART_RX_PIN_MASK \
        ( 1U << 29U ) /*!<@brief PORT pin mask */
                      /* @} */

    /*! @name PIO0_30 (number 94), UART_TX
      @{ */
    #define BOARD_INITPINS_UART_TX_PORT \
        0U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_UART_TX_PIN 30U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_UART_TX_PIN_MASK \
        ( 1U << 30U ) /*!<@brief PORT pin mask */
                      /* @} */

    /*! @name PIO1_4 (number 1), LED_BLUE
      @{ */

    /* Symbols to be used with GPIO driver */
    #define BOARD_INITPINS_LED_BLUE_GPIO \
        GPIO /*!<@brief GPIO peripheral base pointer */
    #define BOARD_INITPINS_LED_BLUE_GPIO_PIN_MASK \
        ( 1U << 4U ) /*!<@brief GPIO pin mask */
    #define BOARD_INITPINS_LED_BLUE_PORT \
        1U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_LED_BLUE_PIN 4U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_LED_BLUE_PIN_MASK \
        ( 1U << 4U ) /*!<@brief PORT pin mask */
                     /* @} */

    /*! @name PIO1_6 (number 5), LED_RED
      @{ */

    /* Symbols to be used with GPIO driver */
    #define BOARD_INITPINS_LED_RED_GPIO \
        GPIO /*!<@brief GPIO peripheral base pointer */
    #define BOARD_INITPINS_LED_RED_GPIO_PIN_MASK \
        ( 1U << 6U ) /*!<@brief GPIO pin mask */
    #define BOARD_INITPINS_LED_RED_PORT \
        1U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_LED_RED_PIN 6U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_LED_RED_PIN_MASK \
        ( 1U << 6U ) /*!<@brief PORT pin mask */
                     /* @} */

    /*! @name PIO1_7 (number 9), LED_GREEN
      @{ */

    /* Symbols to be used with GPIO driver */
    #define BOARD_INITPINS_LED_GREEN_GPIO \
        GPIO /*!<@brief GPIO peripheral base pointer */
    #define BOARD_INITPINS_LED_GREEN_GPIO_PIN_MASK \
        ( 1U << 7U ) /*!<@brief GPIO pin mask */
    #define BOARD_INITPINS_LED_GREEN_PORT \
        1U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_LED_GREEN_PIN 7U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_LED_GREEN_PIN_MASK \
        ( 1U << 7U ) /*!<@brief PORT pin mask */
                     /* @} */

    /*! @name PIO1_9 (number 10), USER_BUTTON
      @{ */

    /* Symbols to be used with GPIO driver */
    #define BOARD_INITPINS_USER_BUTTON_GPIO \
        GPIO /*!<@brief GPIO peripheral base pointer */
    #define BOARD_INITPINS_USER_BUTTON_GPIO_PIN_MASK \
        ( 1U << 9U ) /*!<@brief GPIO pin mask */
    #define BOARD_INITPINS_USER_BUTTON_PORT \
        1U /*!<@brief PORT peripheral base pointer */
    #define BOARD_INITPINS_USER_BUTTON_PIN 9U /*!<@brief PORT pin number */
    #define BOARD_INITPINS_USER_BUTTON_PIN_MASK \
        ( 1U << 9U ) /*!<@brief PORT pin mask */
                     /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins( void ); /* Function assigned for the Cortex-M33 (Core #0)
                              */

    #if defined( __cplusplus )
}
    #endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
