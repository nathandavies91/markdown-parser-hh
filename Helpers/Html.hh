<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class Html extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = false;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = true;

	/**
	 * @var string Parser regex
	 * Example: <{content}>   =>   <{content}>
	 */
	public static string $regex = "/^(<|<\/)[a-z]{1,}(|( |>).*)>$/";

	/**
	 * Markup for the HTML element
	 * @param array<string> $content The html content
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return $content[0];
	}
}
