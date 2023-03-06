# Pico-Game-Controller-QMK

This is a QMK/Via port of [@speedypotato](https://github.com/speedypotato)'s [Pico-Game-Controller](https://github.com/speedypotato/Pico-Game-Controller), which is firmware for RP2040-based SDVX controllers he makes and sells at [his store](https://www.speedylabs.us/). Currently, the only hardware supported by this port is the [Pocket SDVX Pico v4](https://github.com/speedypotato/Pocket-SDVX-Pico-v4) (not the v5), since I own the v4 and can test on it.

## Install

To use this firmware, download the [default](build/pocket_sdvx_pico_default.uf2) or [VIA](build/pocket_sdvx_pico_via.uf2) uf2 (I recommend VIA). Then hold the bootsel button on the bottom of the controller and plug the controller in. Then copy the uf2 to the RPI-RP2 storage device that pops up.

## Default controls/settings

For both builds, the default controls are gamepad controls immediately compatible with SDVX EAC. You can press the little extra button to switch to and from the keyboard/mouse mode. Details are found in [keymap.c](pocket_sdvx_pico/keymaps/default/keymap.c). The default lighting is a rainbow swirl.
## Configuring VIA

If you installed the VIA build, you can customize key bindings, lighting effects, and add macros. Since this controller's cconfiguration hasn't been added to [VIA's repository](https://github.com/the-via/keyboards), you will need to download [via.json](via/via.json). Then, go to [usevia.app](https://usevia.app/) on a supported browser or install the [election wrapper](https://github.com/the-via/releases/releases). Click the settings icon, switch on "Show Design Tab", and then in the design tab click "Load" and select the via.json you downloaded. Go to the configure tab and authorize the controller.

The default layer looks like junk, but those are just keycodes for gamepad buttons. You can [read the docs](https://docs.qmk.fm/#/keycodes) to see more information on possible keycodes. One idea I had is to rebind the extra button to `MO(2)` (momentarily activate layer 2 by holding the button) and then bind the encoders on layer 2 to do things like change the volume(`KC_VOLD` and `KC_VOLU`). Then you can change your system volume by turning an encoder while holding the extra button.

There are also a bunch of lighting modes that come with QMK. I don't think the "Effect Speed" slider actually does anything. The number next to the effect names is the speed.

## Not implemented yet

There is no reactive lighting like the Turbocharger mode yet. I would also like to support the v5 controller at some point, and will do some refactoring along with that. The encoders navigating menus might need some tweaking too.
