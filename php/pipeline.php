#!/usr/bin/php
<?php
$offset = intval($argv[1]);
$limit = intval($argv[2]);
$mysqli = mysqli_connect("168.143.179.129", "pharosbackend", "zub3aFrA", "muco");
if (mysqli_connect_errno($mysqli)) {
    echo "Failed to connect to MySQL: ".mysqli_connect_error();
}
$query = "SELECT concat('archive_collection|',cast(a.archive_collection_id as char)) as object_id, 'ControlledVocabulary' as object_type, 'archive_collection' as object_subtype, concat('archive_collection|',cast(a.archive_collection_id as char)) as group_id, a.archive_collection_id, a.name, a.alternate_name, a.collection_identifier, a.description, a.image_id, if(a.start_date = '', NULL, concat(substring(a.start_date,1,4))) as start_date, if(a.end_date = '', NULL, concat(substring(a.end_date,1,4))) as end_date, cast(group_concat(distinct b.org_term separator '|') as char) as donor_institution, cast(group_concat(distinct c.org_term separator '|') as char) as holding_institution, cast(group_concat(distinct d.org_term separator '|') as char) as archive, cast(group_concat(distinct e.brief_name separator '|') as char) as donor_person FROM archive_collection a LEFT JOIN (archive_collection__organization ab, organization b) ON ab.org_type='donor' and ab.archive_collection_id = a.archive_collection_id and ab.org_id=b.org_id LEFT JOIN (archive_collection__organization ac, organization c) ON ac.org_type='holding' and ac.archive_collection_id = a.archive_collection_id and ac.org_id=c.org_id LEFT JOIN (archive_collection__organization ad, organization d) ON ad.org_type='archive' and ad.archive_collection_id = a.archive_collection_id and ad.org_id=d.org_id LEFT JOIN (archive_collection__person ae, person e) ON (ae.archive_collection_id=a.archive_collection_id and ae.person_id=e.person_id) where (a.canonical_archive_collection_id = 0 or a.canonical_archive_collection_id is null) group by object_id, object_type, object_subtype, group_id, a.archive_collection_id, a.name, a.alternate_name, a.collection_identifier order by a.archive_collection_id LIMIT "
    .$offset.",".$limit;
$res = mysqli_query($mysqli, $query);

$output = new DOMDocument('1.0', 'utf-8');
$output->formatOutput = true;
$outputadd = $output->createElement('add');
$output->appendChild($outputadd);

while ($row = mysqli_fetch_assoc($res)) {
    //        print_r($row);
    $outputdoc = $output->createElement('doc');
    $outputadd->appendChild($outputdoc);

    $generalField = array('object_id','object_type','object_subtype','archive_collection_id');

    foreach ($generalField as $field) {
        $outputcontent = $output->createElement('field', htmlentities($row[$field], ENT_IGNORE));
        $domAttribute = $output->createAttribute('name');
        $domAttribute->value = $field;
        $outputcontent->appendChild($domAttribute);
        $outputdoc->appendChild($outputcontent);
    }

    $optionField = array(
        'name' => 'archive_collection_term',
        'alternate_name' => 'alternate_name',
        'collection_identifier' => 'collection_identifier',
        'description' => 'collection_description',
        'image_id' => 'image_id',
        'start_date' => 'start_date',
        'end_date' => 'end_date',
    );

    foreach ($optionField as $field => $value) {
        if (isset($row[$field]) && $row[$field] != '') {
            $outputcontent = $output->createElement('field', htmlentities($row[$field], ENT_IGNORE));
            $domAttribute = $output->createAttribute('name');
            $domAttribute->value = $value;
            $outputcontent->appendChild($domAttribute);
            $outputdoc->appendChild($outputcontent);
        }
    }

    $multivalueField = array(
        'donor_institution' => 'donor_institution',
        'holding_institution' => 'holding_institution',
        'archive' => 'archive',
        'donor_person' => 'donor_person',
    );

    foreach ($multivalueField as $field => $value) {
        if (isset($row[$field]) && $row[$field] != '') {
            $vals = explode('|', $row[$field]);
            foreach ($vals as $val) {
                $outputcontent = $output->createElement('field', htmlentities($val, ENT_IGNORE));
                $domAttribute = $output->createAttribute('name');
                $domAttribute->value = $value;
                $outputcontent->appendChild($domAttribute);
                $outputdoc->appendChild($outputcontent);
            }
        }
    }

    $requireField = array(
        'display_order' => '0',
        'format' => 'series',
        'group_id' => '0',
        'unitaccess' => 'LAZR-CV',
        'countryfilter' => 'AD AE AF AG AI AL AM AO AQ AR AS AT AU AW AX AZ BA BB BD BE BF BG BH BI BJ BL BM BN BO BQ BR BS BT BV BW BY BZ CA CC CD CF CG CH CI CK CL CM CN CO CR CU CV CW CX CY CZ DE DJ DK DM DO DZ EC EE EG EH ER ES ET FI FJ FK FM FO FR GA GB GD GE GF GG GH GI GL GM GN GP GQ GR GS GT GU GW GY HK HM HN HR HT HU ID IE IL IM IN IO IQ IR IS IT JE JM JO JP KE KG KH KI KM KN KP KR KW KY KZ LA LB LC LI LK LR LS LT LU LV LY MA MC MD ME MF MG MH MK ML MM MN MO MP MQ MR MS MT MU MV MW MX MY MZ NA NC NE NF NG NI NL NO NP NR NU NZ OM PA PE PF PG PH PK PL PM PN PR PS PT PW PY QA RE RO RS RU RW SA SB SC SD SE SG SH SI SJ SK SL SM SN SO SR SS ST SV SX SY SZ TC TD TF TG TH TJ TK TL TM TN TO TR TT TV TW TZ UA UG UM US UY UZ VA VC VE VG VI VN VU WF WS YE YT ZA ZM ZW',
    );

    foreach ($requireField as $field => $value) {
        $outputcontent = $output->createElement('field', $value);
        $domAttribute = $output->createAttribute('name');
        $domAttribute->value = $field;
        $outputcontent->appendChild($domAttribute);
        $outputdoc->appendChild($outputcontent);
    }
}
$output->save("/data/content/archive_collection/chunk".intval($argv[1]).".xml");
echo "Finished ".$argv[1]."\n";
