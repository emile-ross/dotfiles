typedef enum 
{
    V_1 = 100,
    V_1_2 = 120,
    V_1_3 = 130,
    V_1_4 = 140,
    V_2 = 200,
    V_2_1 = 210,
    V_2_2 = 220,
    V_2_3 = 230,
    V_2_4 = 240,
    V_2_5 = 250,
    V_3 = 300,
    V_3_1 = 310,
    V_3_2 = 320,
    V_3_3 = 330,

    STABLE = V_3_1,
    LATEST = V_3_2,
    NEXT = V_3_3,
} df_version;

typedef enum 
{
    CONF_UNKNOWN = 0,
    CONF_BASH,
    CONF_BTOP,
    CONF_BPYT,
    CONF_CAVA,
    CONF_FAST,
    CONF_FUZZ,
    CONF_GTKL,
    CONF_HYPR,
    CONF_KITT,
    CONF_MPVF,
    CONF_NVIM,
    CONF_SWAY,
    CONF_WAYB,
    CONF_ZSHH
} config_name;

typedef enum
{
    INVALID_INPUT = 2,
    YAY_INST_U = 5,
    FEATURE_IN_DEV = 6,
    FEAT_DEPRECATED = 7,
    MAKEPKG_FAIL = 51,
    UNSUPPORTED_DISTRO = 101,
    FUZZ_THEME_FAIL = 103,
    KITTY_PKG_NOT_FOUND = 104,
    FAIL_FIND_HOME_DIR = 204,
    NO_SUCH_FILE_OR_DIR = 205,
    POPEN_FAILED = 206,
    UNKNOWN_AWSM_VERSION = 207,
    CLI_UNKNOWN_PKG = 301,
    CLI_INVALID_CMD_SYNTAX = 302,
    CLI_INVALID_FLAG = 303,
    CLI_ARGS_MISSING = 304,
} error_code_e;

typedef enum
{
    blue = 1,
    flamingo,
    green,
    lavender,
    maroon,
    mauve,
    peach,
    pink,
    red,
    rosewater,
    sapphire,
    sky,
    teal,
    yellow,
} fuzzel_colour_e;
