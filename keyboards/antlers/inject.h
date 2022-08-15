switch (combo_index) {
    case UML_AE:
        if (pressed) {
            if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                SEND_STRING(SS_TAP(X_RALT) "\"A");
            } else {
                SEND_STRING(SS_TAP(X_RALT) "\"a");
            }
        }
        break;
    case UML_OE:
        if (pressed) {
            if ((get_mods() | get_oneshot_mods() )& MOD_MASK_SHIFT) {
                SEND_STRING(SS_TAP(X_RALT) "\"O");
            } else {
                SEND_STRING(SS_TAP(X_RALT) "\"o");
            }
        }
        break;
    case UML_UE:
        if (pressed) {
            if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                SEND_STRING(SS_TAP(X_RALT) "\"U");
            } else {
                SEND_STRING(SS_TAP(X_RALT) "\"u");
            }
        }
        break;
}
