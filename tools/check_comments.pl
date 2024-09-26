#!/usr/bin/perl
use strict;
use warnings;
use File::Find;

# Функция для проверки наличия комментариев в файле
sub check_comments {
    my $file = $_;

    # Проверяем, является ли это файл с расширением .cpp или .h
    if ($file =~ /\.(cpp|h)$/) {
        open my $fh, '<', $file or die "Не могу открыть файл '$file': $!";
        my $has_comments = 0;

        while (my $line = <$fh>) {
            if ($line =~ /^\s*\/\// || $line =~ /^\s*\/\*\*?/) {
                print "Комментарий найден в файле: $file\n";
                $has_comments = 1;
                last;  # Прерываем чтение файла, если комментарий найден
            }
        }

        close $fh;
    }
}

# Переходим к корневой директории проекта (замените 'путь_к_корневой_директории' на актуальный путь)
my $root_directory = './';  # Относительный путь к корневой директории
chdir $root_directory or die "Не могу перейти в корневую директорию: $!";

# Используем File::Find для рекурсивного обхода файловой системы
find(\&check_comments, '.');

# Выводим текущую директорию после проверки всех файлов
my $current_dir = `pwd`;  # Получаем текущую директорию
print "Текущая директория после проверки: $current_dir\n";  # Печатаем её
