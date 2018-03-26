<?hh // strict

/**
 * Markdown Parser
 * @author Nathan Davies, http://nathandavies.ninja
 * @copyright Copyright (c) 2016, Nathan Davies
 */

namespace Markdown\Helpers;

use Markdown\Helper;
use Markdown\Interfaces\BlockElement;

class OrderedList extends Helper implements BlockElement
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
	 * Example: 12. {content}   =>   <ol><li>{content}</li></ol>
	 */
	public static string $regex = "/^[0-9]{1,}[.](?<content>.*)/";

	/**
	 * Markup for the ordered list element
	 * @param array<array<string>> $content List items; with their regex values: content
	 * @return string The markup
	 */
	public static function markup(array<array<string>> $content) : string
	{
		foreach ($content as $listItem)
			$markup [] = parent::markup($listItem["content"], "li");

		return parent::markup($markup, "ol");
	}
}
