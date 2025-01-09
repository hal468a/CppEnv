@echo off

:: 檢查 Docker Desktop 是否啟動
docker info >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Docker Desktop is not running. Attempting to start Docker Desktop...

    :: 啟動 Docker Desktop（適用於 Windows 預設安裝位置）
    start "" "C:\Program Files\Docker\Docker\Docker Desktop.exe"

    :: 等待 Docker Desktop 啟動
    :wait
    timeout /t 3 >nul
    docker info >nul 2>nul
    if %ERRORLEVEL% NEQ 0 (
        echo Waiting for Docker Desktop to start...
        goto wait
    )

    echo Docker Desktop is now running.
)

:: 執行 docker compose 指令
docker compose run --rm CppEnv