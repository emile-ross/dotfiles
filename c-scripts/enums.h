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
    CONF_UNKNOWN,
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
} pkg_conf_name;

typedef enum
{
    INVALID_INPUT = 2,
    YAY_INST_U = 5,
}
   
    

extern enum error_code_e;

// error_code_e error_message_code = err_code;

