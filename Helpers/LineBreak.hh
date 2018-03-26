<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class LineBreak extends Helper implements BlockElement
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
	 * Example 1: ---  =>  <hr />
	 * Example 2: ***  =>  <hr />
	 */
	public static string $regex = "/^([-* ]{3,})$/";

	/**
	 * Markup for the line break element
	 * @param array<string> $content Regex values
	 * @return string The markup
	 */
	public static function markup(array<string> $content) : string
	{
		return "<hr />";
	}
}
