{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.clang           # Компилятор clang
    pkgs.ccls            # Языковой сервер для C/C++
    pkgs.gdb             # Отладчик
    pkgs.cmake           # Для сборки C++ проектов
    pkgs.catch2          # Catch2 для тестирования
    pkgs.perl            # Для выполнения Perl-скриптов
  ];
}
