#!/bin/bash
cd "$(dirname "$0")"
wine StarterBot.exe &
cd ../starcraft
wine Chaoslauncher.exe
