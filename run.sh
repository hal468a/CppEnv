#!/bin/bash

# 檢查 Docker Desktop 是否啟動
if ! docker info >/dev/null 2>&1; then
  echo "Docker Desktop is not running. Attempting to start Docker Desktop..."

  # 啟動 Docker Desktop（適用於 macOS 預設安裝位置）
  open -a Docker

  # 等待 Docker Desktop 啟動
  while ! docker info >/dev/null 2>&1; do
    echo "Waiting for Docker Desktop to start..."
    sleep 3
  done

  echo "Docker Desktop is now running."
fi

# 執行 docker compose 指令
docker compose run --rm CppEnv