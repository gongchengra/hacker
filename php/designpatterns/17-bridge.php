<?php
/**
 * SECTION 1: Implementor hierarchy.
 * Implementor: a small bean that provides basic methods for accessing
 * data on a single Website.
 */
interface WebsiteImplementor
{
    /**
     * @param string $address
     * @return boolean
     */
    public function containsLinkTo($address);

    /**
     * @return string
     */
    public function getAddress();
}

/**
 * ConcreteImplementor.
 * Another implementation could be CrawlerWebsiteImplementor which scans pages
 * on a as-needed basis to find links.
 */
class IndexedWebsiteImplementor implements WebsiteImplementor
{
    private $_address;
    private $_links;

    public function __construct($address, array $linked)
    {
        $this->_address = $address;
        $this->_links = $linked;
    }

    public function getAddress()
    {
        return $this->_address;
    }

    public function containsLinkTo($address)
    {
        return in_array($address, $this->_links);
    }
}

/**
 * SECTION 2: Abstraction hierarchy.
 * Abstraction.
 * Additional operation can be concrete methods on an abstract class,
 * but a Bridge frees the Implementors from extending a single base class.
 * For example, different Abstractions can use the same Implementor
 * objects and classes if necessary, while if Implementor extends something
 * it remains tied to the base class.
 */
class Website
{
    private $_imp;

    public function __construct(WebsiteImplementor $imp)
    {
        $this->_imp = $imp;
    }

    public function getAddress()
    {
        return $this->_imp->getAddress();
    }

    public function containsLinkTo($anotherWebsite)
    {
        if ($anotherWebsite instanceof Website) {
            $anotherWebsite = $anotherWebsite->getAddress();
        }
        return $this->_imp->containsLinkTo($anotherWebsite);
    }

    public function containsLinks(array $addresses)
    {
        $result = true;
        foreach ($addresses as $a) {
            if (!$this->containsLinkTo($a)) {
                $result = false;
            }
        }
        return $result;
    }
}

/**
 * RefinedAbstraction for presentation purposes.
 * It would not be possible to create a PresentationWebsite which presents
 * the same interface to the Client *for every type of WebsiteImplementor*
 * if we were using an abstract class (that ConcreteImplementors extend)
 * for the Abstraction operations.
 * In that case, we would have been forced to create PresentationIndexedWebsite,
 * PresentationCrawlerWebsite, ...
 */
class PresentationWebsite extends Website
{
    public function getAddress()
    {
        $address = 'http://' . parent::getAddress();
        return "<a href=\"$address\">$address</a>";
    }
}

$links = array('www.google.com', 'www.twitter.com', 'www.youtube.com', 'giorgiosironi.blogspot.com');
$websiteImp = new IndexedWebsiteImplementor('www.blogger.com', $links);
$website = new Website($websiteImp);
var_dump($website->containsLinks(array('www.google.com', 'www.youtube.com')));
$presentationWebsite = new PresentationWebsite($websiteImp);
echo $presentationWebsite->getAddress(), "\n";
