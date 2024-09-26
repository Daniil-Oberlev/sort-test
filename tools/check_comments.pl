#!/usr/bin/perl
use strict;
use warnings;
use File::Find;

sub check_comments {
  my $file = $_;

  if ( $file =~ /\.(cpp|h|hpp)$/ ) {
    open my $fh, '<', $file or die "Не могу открыть файл '$file': $!";
    my $has_comments = 0;

    while ( my $line = <$fh> ) {
      if ( $line =~ /^\s*\/\// || $line =~ /^\s*\/\*\*?/ ) {
        print "Комментарий найден в файле: $file\n";
        $has_comments = 1;
        last;
      }
    }

    close $fh;
  }
}

my $root_directory = './';
chdir $root_directory or die "Не могу перейти в корневую директорию: $!";

find( \&check_comments, '.' );

my $current_dir = `pwd`;
print "Текущая директория после проверки: $current_dir\n";
