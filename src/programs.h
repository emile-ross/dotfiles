
typedef struct
{
	const char *config_dir;
	const char *config_list;
	const char *repo_dir;
	const char *package_name;
} program_conf_type;

static program_conf_type bash_data = 
{
	"~/",
	".bashrc",
	"shell/bash/",
	NULL,
};
static program_conf_type bpytop = 
{
	"~/.config/bpytop/",
	"bpytop.conf",
	"bpytop/",
	"bpytop",
};
static program_conf_type btop_data = 
{
	"~/.config/btop/",
	"btop.conf",
	"btop/",
	"btop",
};
static program_conf_type cava_data = 
{
	"~/.config/cava/",
	"config",
	"cava/",
	"cava",
};

static program_conf_type fastfetch = 
{
	"~/.config/fastfetch/",
	"config.conf config-other.conf config-default.conf",
	"fastfetch/",
	"fastfetch",
};

static program_conf_type fuzzel = 
{
	"~/.config/fuzzel/",
	"fuzzel.ini old-fuzzel.ini default-fuzzel.ini fuzzel-duplicated.ini",
	"fuzzel/",
	"fuzzel",
};

static program_conf_type gtklock = 
{
	"~/.config/gtklock/",
	"style.css lockscreen.jpg",
	"gtklock/",
	"gtklock",
};

static program_conf_type hyprland = 
{
	"~/.config/hypr/",
	"hyprland.conf hypridle.conf hyprlock.conf hyprpaper.conf",
	"hypr/",
	"hyprland hyprpaper hyprpicker hyprlock hypridle",
};

static program_conf_type kitty = 
{
	"~/.config/kitty/",
	"kitty.conf",
	"kitty/",
	"kitty"
};

static program_conf_type mpv = 
{
	"~/.config/mpv/",
	"mpv.conf",
	"mpv/",
	"mpv",
};

static program_conf_type nvim_data = 
{
	"~/.config/nvim/",
	"init.lua dark-init.lua",
	"nvim/",
	"nvim"
};

static program_conf_type rofi_data = 
{
	"~/.config/rofi/",
	"config.rasi",
	"rofi/",
	"rofi",
};

static program_conf_type sway_data = 
{
	"~/.config/sway/",
	"config",
	"sway/",
	"sway",
};

static program_conf_type waybar = 
{
	"~/.config/waybar/",
	"config.jsonc style.css",
	"waybar/",
	"waybar"
};

static program_conf_type zsh = 
{
	"~/",
	".zshrc",
	"shell/zsh/",
	"zsh"
};

