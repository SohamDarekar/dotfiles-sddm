# Silent SDDM Theme - Personal Dotfiles Backup

> [!NOTE]
> This is my personal backup repository for the Silent SDDM theme files. This repository serves as a safety backup in case of system errors or configuration issues.

## About This Repository

This repository contains my customized version of the Silent SDDM theme files (version 1.3.0). These are backup copies of my actual SDDM theme configuration that should be installed at `/usr/share/sddm/themes/silent/` on the system.

**Current Active Configuration**: `desk.conf` - A configuration with animated desk background

## ⚠️ Important Notes

- **Active Files Location**: The actual working theme files are located at `/usr/share/sddm/themes/silent/` on my system
- **Backup Purpose**: This repository is primarily for backup and version control of my theme customizations
- **System Recovery**: In case of system issues, these files can be used to restore my SDDM theme configuration

## Quick Restore

If you need to restore the theme from this backup:

```bash
# Clone this repository
git clone <this-repo-url>
cd silent

# Copy files to the correct location (requires sudo)
sudo mkdir -p /usr/share/sddm/themes/silent
sudo cp -rf . /usr/share/sddm/themes/silent/

# Install fonts
sudo cp -r /usr/share/sddm/themes/silent/fonts/* /usr/share/fonts/

# Update SDDM configuration
sudo nano /etc/sddm.conf
```

Make sure `/etc/sddm.conf` contains:
```ini
[General]
InputMethod=qtvirtualkeyboard
GreeterEnvironment=QML2_IMPORT_PATH=/usr/share/sddm/themes/silent/components/

[Theme]
Current=silent
```

## System Requirements

### Dependencies
Ensure these packages are installed:
- SDDM ≥ 0.21
- QT ≥ 6.5
- qt6-svg
- qt6-virtualkeyboard  
- qt6-multimedia
- For video backgrounds: FFmpeg (optional, for background utilities)

### Automatic Installation
The repository includes an installation script that handles dependencies for major distributions:
```bash
./install.sh
```
Supported package managers: `pacman`, `xbps`, `dnf`, `zypper`

## Configuration Files

The `configs/` directory contains various theme presets. To enable a specific theme:

1. **Create a new config**: Place your `.conf` file in the `configs/` directory
2. **Add to metadata**: Add the config file path to `metadata.desktop` 
3. **Switch active config**: Comment out the current active `ConfigFile=` line with `;` and uncomment your desired config

Example in `metadata.desktop`:
```ini
; ConfigFile=configs/default.conf
; ConfigFile=configs/rei.conf
  ConfigFile=configs/desk.conf    # Currently active
; ConfigFile=configs/your-custom.conf
```

### Available Configurations:
- `default.conf` - Original default theme
- `default-left.conf` / `default-right.conf` - Layout variants
- `desk.conf` - **Currently Active** - Animated desk setup
- `rei.conf`, `ken.conf`, `silvia.conf` - Anime-themed configs
- `catppuccin-latte.conf`, `catppuccin-frappe.conf`, `catppuccin-macchiato.conf`, `catppuccin-mocha.conf` - Catppuccin color scheme variants
- `cyber.conf` - Cyberpunk themed

### Background Assets:
The theme includes both static images and animated MP4 backgrounds:
- Animated backgrounds: `desk.mp4`, `rei.mp4`, `ken.mp4`, `silvia.mp4`, `cyber.mp4`, `kirokaze-0.mp4`, `kirokaze-1.mp4`
- Static fallbacks: Corresponding PNG files for each animated background
- Additional static backgrounds: `default.jpg`, `mountain.jpg`, `relief.jpg`, `smoky.jpg`

## Available Scripts

### Core Scripts
- `./install.sh` - Automated installation script with dependency management
- `./test.sh` - Test the theme before applying changes (supports debug mode with `-d` flag)
- `./change_avatar.sh <username> <image_path>` - Change user avatar

### Background Utilities
- `backgrounds/extract_first_frame.sh <video>` - Extract PNG thumbnail from MP4 backgrounds

## Testing

Before applying any changes, always test the theme:
```bash
cd /usr/share/sddm/themes/silent/
./test.sh

# For debug mode with verbose output:
./test.sh -d
```

## Credits

- **[SilentSDDM](https://github.com/uiriansan/SilentSDDM)**: Original theme files and development
- **[Kirokaze](https://www.deviantart.com/kirokaze)**: Animated backgrounds (`kirokaze-0.mp4`, `kirokaze-1.mp4`) and visual assets
- **Original Contributors**: All the developers and contributors of the original SilentSDDM project
- **Theme Assets**: Various anime and aesthetic backgrounds from multiple sources

## Repository Structure

```
├── Main.qml              # Main theme file
├── metadata.desktop      # Theme metadata
├── configs/             # Theme configuration presets
├── components/          # QML components
├── backgrounds/         # Background images and utilities
├── fonts/              # Theme fonts
├── icons/              # Icon assets
└── docs/               # Documentation and previews
```

---

*This is a personal backup repository. For the official SilentSDDM theme, visit the [original repository](https://github.com/uiriansan/SilentSDDM).*
