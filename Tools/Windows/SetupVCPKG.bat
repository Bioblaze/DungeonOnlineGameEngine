@echo off
SET VCPKG_ROOT=%CD%\vcpkg
SET VCPKG_GIT_URL=https://github.com/microsoft/vcpkg.git
SET SETTINGS_JSON_PATH=%CD%\settings.json
SET CMAKE_JSON_PATH=%CD%\CMakeUserPresets.json

:: Convert and escape the vcpkg directory path
SET ESCAPED_VCPKG_ROOT=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
SET NEW_TOOLCHAIN_FILE=%ESCAPED_VCPKG_ROOT%


:: Check if vcpkg directory exists
if not exist "%VCPKG_ROOT%" (
    :: Clone vcpkg
    echo Cloning vcpkg into %VCPKG_ROOT%...
    git clone %VCPKG_GIT_URL% %VCPKG_ROOT%
    if errorlevel 1 (
        echo Failed to clone vcpkg.
        exit /b %errorlevel%
    )

    :: Bootstrap vcpkg
    echo Bootstrapping vcpkg...
    call %VCPKG_ROOT%\bootstrap-vcpkg.bat
    if errorlevel 1 (
        echo Failed to bootstrap vcpkg.
        exit /b %errorlevel%
    )

    :: Integrate vcpkg with Visual Studio
    :: Integrate vcpkg with Visual Studio and check if already integrated
    echo Checking vcpkg integration with Visual Studio...
    FOR /F "tokens=*" %%i IN ('%VCPKG_ROOT%\vcpkg integrate install') DO SET INTEGRATION_RESULT=%%i
    echo %INTEGRATION_RESULT%
    IF "%INTEGRATION_RESULT%"=="Applied user-wide integration for this vcpkg root." (
        echo vcpkg is already integrated with Visual Studio.
    ) ELSE IF "%INTEGRATION_RESULT%"=="All installed packages are currently up to date." (
        echo No new packages to integrate.
    ) ELSE (
        echo Integration command executed.
    )
) else (
    echo vcpkg directory already exists. Assuming user-wide integration is in place.
)

:: Update settings.json with the new CMAKE_TOOLCHAIN_FILE path
echo Updating settings.json with new CMAKE_TOOLCHAIN_FILE path...
powershell -Command "$json = Get-Content '%SETTINGS_JSON_PATH%' | Out-String | ConvertFrom-Json; $json.'cmake.configureSettings'.CMAKE_TOOLCHAIN_FILE = '%NEW_TOOLCHAIN_FILE%'; $json | ConvertTo-Json | Set-Content '%SETTINGS_JSON_PATH%'"

if %errorlevel% neq 0 (
    echo Failed to update settings.json.
    exit /b %errorlevel%
)

echo settings.json updated successfully.

:: Update CMakeUserPresets.json with the new CMAKE_TOOLCHAIN_FILE path
echo Updating CMakeUserPresets.json with new CMAKE_TOOLCHAIN_FILE path...
powershell -Command "$json = Get-Content '%CMAKE_JSON_PATH%' | Out-String | ConvertFrom-Json; $json.configurePresets[0].cacheVariables.VCPKG_ROOT = '%NEW_TOOLCHAIN_FILE%'; $json | ConvertTo-Json -Depth 100 | Set-Content '%CMAKE_JSON_PATH%'"

if %errorlevel% neq 0 (
    echo Failed to update settings.json.
    exit /b %errorlevel%
)

echo CMakeUserPresets.json updated successfully.

:: Install packages without specifying which ones (the script user should modify this part)
echo Proceeding to install packages...
call %VCPKG_ROOT%\vcpkg install
if errorlevel 1 (
    echo Failed to install packages. You might have not specified which packages to install.
    exit /b %errorlevel%
)

set PATH=%VCPKG_ROOT%;%PATH%

echo Setup complete!
