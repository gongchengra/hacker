<?php
require_once(__DIR__. '/vendor/autoload.php');
use PHPTrie\Trie;
$trie = new Trie();
$trie->add('key', 10);
$trie->add("This can be any string!", 15);
print $trie->search('key');
//print $trie->search('be');
