<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class UnorderedList extends Helper implements BlockElement
{
	/**
	 * @var bool
	 * Parse inline elements for this block?
	 */
	public static bool $includeInlines = true;

	/**
	 * @var bool
	 * Is the current block element independant (true)?
	 * Or can it contain other block elements (false)?
	 */
	public static bool $isStandalone = false;

	/**
	 * @var string Parser regex
	 * Example 1: - {content}   =>   <ul><li>{content}</li></ul>
	 */
	public static string $regex = "/^[+-](?<content>.*)/";

	/**
	 * Markup for the list element
	 * @param array<array<string>> $content List items; with their regex values: content
	 * @return string The markup
	 */
	public static function markup(array<array<string>> $content) : string
	{
		foreach ($content as $listItem)
			$markup [] = parent::markup($listItem["content"], "li");

		return parent::markup($markup, "ul");
	}
}
