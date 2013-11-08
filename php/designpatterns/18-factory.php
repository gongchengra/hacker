<?php
/**
 * SECTION 1: a WidgetHelper interface and two different implementations.
 *
 * This class purpose is to generate blinking text in spite of all
 * usability recommendations. This is the Product.
 * As always, interfaces in php may be omitted.
 */
interface WidgetHelper
{
    /**
     * @return string
     */
    public function generateHtml($text);
}

/**
 * Implementation that generates html tied to a javascript library.
 * This is one ConcreteProduct.
 */
class JavascriptWidgetHelper implements WidgetHelper
{
    public function generateHtml($text)
    {
        return '<div dojoType="...">' . $text . '</div>';
    }
}

/**
 * Implementation that generates html that loads a flash object.
 * This is one ConcreteProduct.
 */
class FlashWidgetHelper implements WidgetHelper
{
    public function generateHtml($text)
    {
        return '<object>
        <param name="text">' . $text . '</param>
        </object>';
    }
}

/**
 * SECTION 2: a Creator class which defines a seam to change the object it
 * creates during execution.
 *
 * Normally we would inject the chosen WidgetHelper to the Client class, but
 * since WidgetHelpers are created during the execution (basing on business
 * logic) we cannot instantiate them in advance and so we need an abstraction
 * on the creation process to allow reusing and overriding: the Factory Method
 * createWidgetHelper().
 */
abstract class LoginPage
{
    /**
     * @return WidgetHelper
     */
    public abstract function createWidgetHelper();

    /**
     * A Template Method which uses the Factory Method.
     */
    public function render()
    {
        $userId = uniqid('User ');
        // insert all the logic needed here...
        if (true or $complexBusinessLogicRules) {
            $helper = $this->createWidgetHelper();
            return $helper->generateHtml("Welcome, $userId");
        }
    }
}

/**
 * First subclass: creates Javascript-based helpers.
 * This is one ConcreteCreator.
 */
class JavascriptLoginPage extends LoginPage
{
    public function createWidgetHelper()
    {
        return new JavascriptWidgetHelper();
    }
}

/**
 * Second subclass: creates Flash-based helpers.
 * This is one ConcreteCreator.
 */
class FlashLoginPage extends LoginPage
{
    public function createWidgetHelper()
    {
        return new FlashWidgetHelper();
    }
}

$page = new FlashLoginPage();
echo $page->render(), "\n";
$page = new JavascriptLoginPage();
echo $page->render(), "\n";
